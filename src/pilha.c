#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX_ALTURA 10

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

void imprimir_pilhas_lado_a_lado(Pilha* t1, Pilha* t2, Pilha* t3, int max_altura) {
    int discos1[MAX_ALTURA] = {0};
    int discos2[MAX_ALTURA] = {0};
    int discos3[MAX_ALTURA] = {0};

    Nodo* atual = t1->topo;
    for (int i = t1->tamanho - 1; i >= 0; i--) {
        discos1[i] = atual->disco;
        atual = atual->prox;
    }

    atual = t2->topo;
    for (int i = t2->tamanho - 1; i >= 0; i--) {
        discos2[i] = atual->disco;
        atual = atual->prox;
    }

    atual = t3->topo;
    for (int i = t3->tamanho - 1; i >= 0; i--) {
        discos3[i] = atual->disco;
        atual = atual->prox;
    }

    void print_disco(int disco, int max) {
        int espaco = max - disco;
        for (int j = 0; j < espaco; j++) printf(" ");
        if (disco == 0) {
            printf("|");
        } else {
            for (int j = 0; j < disco; j++) printf("*");
            printf("|");
            for (int j = 0; j < disco; j++) printf("*");
        }
        for (int j = 0; j < espaco; j++) printf(" ");
    }

    printf("\n=== ESTADO DAS TORRES ===\n\n");

    for (int i = max_altura - 1; i >= 0; i--)  {
        print_disco(discos1[i], max_altura);
        printf("     ");
        print_disco(discos2[i], max_altura);
        printf("     ");
        print_disco(discos3[i], max_altura);
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < max_altura * 2 + 1; j++) printf("=");
        printf("     ");
    }
    printf("\n");

    int total = max_altura * 2 + 1;
    printf("%*sT1%*s", total / 2 + 1, "", total / 2 + 5, "");
    printf("%*sT2%*s", total / 2, "", total / 2 + 5, "");
    printf("T3\n\n");
}