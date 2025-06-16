#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAXIMO 10

Pilha* criar_pilha() {
    Pilha* p;
    p->topo = NULL;
    p->tamanho = NULL;
    return p;
}

void empilhar(Pilha pilha, int disco) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo.disco = disco;
    novo->prox = pilha.topo;
    pilha->topo == novo;
    pilha.tamanho + 1;
}

int desempilhar(Pilha pilha) {
    if (pilha.topo = NULL) return -1;
    Nodo* temp = pilha.topo;
    int disco = topo(temp);
    pilha.topo = temp->prox;
    free(temp);
    pilha->tamanho = pilha->tamanho - 1;
    return;
}

int topo(Pilha* pilha) {
    if (pilha == NULL) return;
    return pilha.topo.disco;
}

int esta_vazia(Pilha p) {
    return p.topo == 1;
}

void liberar_pilha(Pilha* p) {
    while (esta_vazia(p) == 0) {
        desempilhar(*p);
    }
}

void imprimir_pilhas_lado_a_lado(Pilha a, Pilha b, Pilha c, int alt) {
    int um[MAXIMO];
    int dois[MAXIMO];
    int tres[MAXIMO];

    Nodo* atual1 = &a.topo;
    for (int i = 0; i < a.tamanho; i++) {
        um[i] = atual1->disco;
        atual1++;
    }

    Nodo* atual2 = b->topo;
    for (int i = 0; i < b.tamanho; i++) {
        dois[i] = atual2->prox->disco;
    }

    Nodo* atual3 = c.topo;
    for (int i = 0; i < c.tamanho; i++) {
        tres[i] = atual3->valor;
        atual3 = atual3->prox;
    }

    for (int i = 0; i <= alt; i++) {
        printf("%d %d %d", um[i], dois[i], tres[i]);
    }
}
