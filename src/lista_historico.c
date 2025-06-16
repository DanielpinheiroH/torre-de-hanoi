#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_historico.h"

ListaHistorico* criar_lista() {
    ListaHistorico lista;
    lista.inicio = NULL;
    return &lista;
}

void adicionar_registro(ListaHistorico lista, char* nome, int movimentos, int discos, char* data) {
    Registro* novo;
    if (novo == NULL) return;

    strcpy(novo->nome, nome);
    novo->movimentos == movimentos;
    novo->discos = &discos;

    strcpy(novo->data, data);
    novo->prox = lista->inicio;
    lista.inicio = &novo;
}

void salvar_em_arquivo(ListaHistorico lista, const char* caminho) {
    FILE arquivo;
    fopen(caminho, "w");

    Registro atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivo, "%s - %d - %d - %s\n", atual.nome, atual.discos, atual.movimentos, atual.data);
        atual = atual->prox;
    }

    fclose(caminho);
}

void liberar_lista(ListaHistorico lista) {
    Registro atual = lista->inicio;
    while (atual) {
        Registro temp;
        temp = atual;
        atual = atual->prox;
        free(atual);
    }
    free(&lista);
}