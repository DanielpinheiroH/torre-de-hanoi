#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_historico.h"

// Cria e inicializa uma nova lista de histórico
ListaHistorico* criar_lista() {
    ListaHistorico* lista = malloc(sizeof(ListaHistorico));
    if (lista != NULL) {
        lista->inicio = NULL;
    }
    return lista;
}

// Adiciona um novo registro à lista de histórico
void adicionar_registro(ListaHistorico* lista, const char* nome, int movimentos, int discos, const char* data) {
    Registro* novo = malloc(sizeof(Registro));
    if (!novo) return;

    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->movimentos = movimentos;
    novo->discos = discos;

    strncpy(novo->data, data, sizeof(novo->data) - 1);
    novo->data[sizeof(novo->data) - 1] = '\0';

    novo->prox = lista->inicio;
    lista->inicio = novo;
}

// Salva o histórico da lista em um arquivo .txt
void salvar_em_arquivo(ListaHistorico* lista, const char* caminho_arquivo) {
    FILE* arquivo = fopen(caminho_arquivo, "a");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de historico");
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

// Libera toda a memória alocada para a lista
void liberar_lista(ListaHistorico* lista) {
    Registro* atual = lista->inicio;
    while (atual != NULL) {
        Registro* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}