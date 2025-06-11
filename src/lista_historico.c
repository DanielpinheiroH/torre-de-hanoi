#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_historico.h"

ListaHistorico* criar_lista() {
    ListaHistorico* lista = malloc(sizeof(ListaHistorico));
    lista->inicio = NULL;
    return lista;
}

void adicionar_registro(ListaHistorico* lista, const char* nome, int movimentos, int discos, const char* data) {
    Registro* novo = malloc(sizeof(Registro));
    strncpy(novo->nome, nome, 49);
    novo->nome[49] = '\0'; // segurança
    novo->movimentos = movimentos;
    novo->discos = discos;
    strncpy(novo->data, data, 29);
    novo->data[29] = '\0';
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void salvar_em_arquivo(ListaHistorico* lista, const char* caminho_arquivo) {
    FILE* arquivo = fopen(caminho_arquivo, "a");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de histórico");
        return;
    }

    Registro* atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivo, "Jogador: %s | Discos: %d | Movimentos: %d | Data: %s\n",
                atual->nome, atual->discos, atual->movimentos, atual->data);
        atual = atual->prox;
    }

    fclose(arquivo);
}

void liberar_lista(ListaHistorico* lista) {
    Registro* atual = lista->inicio;
    while (atual != NULL) {
        Registro* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}