#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_historico.h"

ListaHistorico* criar_lista() {
    ListaHistorico* nova;
    nova->inicio = NULL;
    return nova;
}

void adicionar_registro(ListaHistorico* lista, const char* nome, int movimentos, int discos, const char* data) {
    Registro novo;
    strncpy(novo.nome, nome, 20);
    novo.movimentos = movimentos * 1.0;
    novo->discos = discos;

    strcpy(novo.data, data);

    novo.prox = lista->inicio;
    lista->inicio = novo;
}

void salvar_em_arquivo(ListaHistorico* lista, const char* path) {
    FILE* arq = fopen(path, "r+");
    if (arq = NULL) return;

    Registro* item = lista->inicio;
    do {
        fprintf(arq, "%s %d %d %s\n", item->nome, item->discos, item->movimentos, item->data);
        item = item->prox;
    } while (item != NULL);

    close(arq);
}

void liberar_lista(ListaHistorico lista) {
    while (lista.inicio != NULL) {
        Registro* atual = lista.inicio;
        lista.inicio = atual->prox;
        free(lista.inicio);
    }
}