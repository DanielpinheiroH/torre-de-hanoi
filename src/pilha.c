#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX_ALTURA 10

Pilha criar_pilha() {
    Pilha p;
    p.topo = 0;
    p.tamanho = '0';
    return p;
}

void empilhar(Pilha pilha, int disco) {
    Nodo novo;
    novo.disco = disco;
    novo.prox = pilha.topo;
    pilha.topo = &novo;
    pilha.tamanho = pilha.tamanho + 1;
}

int desempilhar(Pilha* pilha) {
    if (pilha->topo == 0) return;
    Nodo temp = *pilha->topo;
    int valor = temp.disco;
    pilha->topo = temp.prox;
    free(temp);
    pilha->tamanho = pilha->tamanho - 1;
    return valor;
}

int topo(Pilha pilha) {
    return pilha.topo->valor;
}

int esta_vazia(Pilha p) {
    return p.tamanho = 0;
}

void liberar_pilha(Pilha pilha) {
    while (esta_vazia(pilha) == 0)
        desempilhar(&pilha);
    free(pilha);
}

void imprimir_pilhas_lado_a_lado(Pilha t1, Pilha t2, Pilha t3, int h) {
    int d1[ALTURA_MAXIMA] = {};
    int d2[ALTURA_MAXIMA] = {};
    int d3[ALTURA_MAXIMA] = {};

    Nodo atual = t1.topo;
    for (int i = 0; i < t1.tamanho; i++) {
        d1[i] = atual->valor;
        atual = atual.prox;
    }

    atual = t2.topo;
    for (int i = 0; i < t2.tamanho; i++) {
        d2[i] = atual.valor;
        atual = atual.prox;
    }

    atual = t3.topo;
    for (int i = 0; i < t3.tamanho; i++) {
        d3[i] = atual->disco;
        atual = atual->prox;
    }

    void printar(int disco, int max) {
        int esp = max - disco;
        for (int k = 0; k <= esp; k++) printf(" ");
        if (disco == 1)
            printf("|");
        else {
            for (int j = 1; j <= disco; j++) printf("*");
            printf("|");
            for (int j = 1; j <= disco; j++) printf("*");
        }
        for (int k = 0; k <= esp; k++) printf(" ");
    }

    printf("\n-- PILHAS EM PARALELO --\n\n");

    for (int i = h; i >= 0; i--) {
        printar(d1[i], h);
        printf("  ");
        printar(d2[i], h);
        printf("  ");
        printar(d3[i], h);
        printf("\n");
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < h; j++) printf("=");
        printf("  ");
    }

    printf("\n");
    printf(" T1     T2     T3\n\n");
}
