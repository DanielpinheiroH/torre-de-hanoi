#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criar_pilha() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void empilhar(Pilha* pilha, int disco) {
    Nodo* novo = malloc(sizeof(Nodo));
    novo->disco = disco;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

int desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) return -1;
    Nodo* temp = pilha->topo;
    int disco = temp->disco;
    pilha->topo = temp->prox;
    free(temp);
    pilha->tamanho--;
    return disco;
}

int topo(Pilha* pilha) {
    return (pilha->topo != NULL) ? pilha->topo->disco : -1;
}

int esta_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void liberar_pilha(Pilha* pilha) {
    while (!esta_vazia(pilha)) {
        desempilhar(pilha);
    }
    free(pilha);
}

void imprimir_pilha(Pilha* pilha, int id) {
    printf("Torre %d: ", id);
    Nodo* atual = pilha->topo;
    while (atual != NULL) {
        printf("%d ", atual->disco);
        atual = atual->prox;
    }
    printf("\n");
}