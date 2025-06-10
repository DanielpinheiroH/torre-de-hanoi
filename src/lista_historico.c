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
    strcpy(novo->nome, nome);
    novo->movimentos = movimentos;
    novo->discos = discos;
    strcpy(novo->data, data);
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void salvar_em_arquivo(ListaHistorico* lista, const char* caminho) {
    FILE* f = fopen(caminho, "a");
    if (!f) return;

    Registro* atual = lista->inicio;
    while (atual) {
        fprintf(f, "%s,%d,%d,%s\n", atual->nome, atual->movimentos, atual->discos, atual->data);
        atual = atual->prox;
    }

    fclose(f);
}

void mostrar_historico(ListaHistorico* lista) {
    Registro* atual = lista->inicio;
    while (atual) {
        printf("Jogador: %s | Movimentos: %d | Discos: %d | Data: %s\n",
               atual->nome, atual->movimentos, atual->discos, atual->data);
        atual = atual->prox;
    }
}

void buscar_por_nome(ListaHistorico* lista, const char* nome) {
    Registro* atual = lista->inicio;
    int achou = 0;
    while (atual) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Jogador: %s | Movimentos: %d | Discos: %d | Data: %s\n",
                   atual->nome, atual->movimentos, atual->discos, atual->data);
            achou = 1;
        }
        atual = atual->prox;
    }
    if (!achou) {
        printf("Nenhum registro encontrado para %s.\n", nome);
    }
}

void liberar_lista(ListaHistorico* lista) {
    Registro* atual = lista->inicio;
    while (atual) {
        Registro* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}