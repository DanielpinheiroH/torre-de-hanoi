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
    Nodo* discos1[MAX_ALTURA] = {0};
    Nodo* discos2[MAX_ALTURA] = {0};
    Nodo* discos3[MAX_ALTURA] = {0};

    Nodo* atual = t1->topo;
    for (int i = 0; i < t1->tamanho; i++) {
        discos1[i] = atual;
        atual = atual->prox;
    }

    atual = t2->topo;
    for (int i = 0; i < t2->tamanho; i++) {
        discos2[i] = atual;
        atual = atual->prox;
    }

    atual = t3->topo;
    for (int i = 0; i < t3->tamanho; i++) {
        discos3[i] = atual;
        atual = atual->prox;
    }

    int largura_max = max_altura;

    printf("\n=== ESTADO DAS TORRES ===\n\n");

    for (int i = max_altura - 1; i >= 0; i--) {
        int d1 = (i < t1->tamanho && discos1[i]) ? discos1[i]->disco : 0;
        int d2 = (i < t2->tamanho && discos2[i]) ? discos2[i]->disco : 0;
        int d3 = (i < t3->tamanho && discos3[i]) ? discos3[i]->disco : 0;

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

        // alinhamento uniforme entre colunas
        print_disco(d1, largura_max);
        printf("     ");
        print_disco(d2, largura_max);
        printf("     ");
        print_disco(d3, largura_max);
        printf("\n");
    }

    // base das torres
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < largura_max * 2 + 1; j++) printf("=");
        printf("     ");
    }
    printf("\n");

    // nomes das torres
    int total_largura = largura_max * 2 + 1;
    printf("%*sT1%*s", total_largura / 2 + 1, "", total_largura / 2 + 5, "");
    printf("%*sT2%*s", total_largura / 2, "", total_largura / 2 + 5, "");
    printf("T3\n\n");
}
