#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void imprimir_pilhas_lado_a_lado(Pilha* t1, Pilha* t2, Pilha* t3, int altura_maxima) {
    int matriz[3][altura_maxima];
    for (int i = 0; i < altura_maxima; i++) {
        matriz[0][i] = 0;
        matriz[1][i] = 0;
        matriz[2][i] = 0;
    }

    Nodo* atual = t1->topo;
    for (int i = 0; atual && i < altura_maxima; i++) {
        matriz[0][altura_maxima - 1 - i] = atual->disco;
        atual = atual->prox;
    }

    atual = t2->topo;
    for (int i = 0; atual && i < altura_maxima; i++) {
        matriz[1][altura_maxima - 1 - i] = atual->disco;
        atual = atual->prox;
    }

    atual = t3->topo;
    for (int i = 0; atual && i < altura_maxima; i++) {
        matriz[2][altura_maxima - 1 - i] = atual->disco;
        atual = atual->prox;
    }

    printf("\n=== ESTADO DAS TORRES ===\n");

    for (int i = 0; i < altura_maxima; i++) {
        for (int t = 0; t < 3; t++) {
            int disco = matriz[t][i];
            int total_largura = altura_maxima;

            int largura_disponivel = total_largura * 2 + 1;
            int largura_disco = disco * 2 + 1;

            int espacos_laterais = (largura_disponivel - largura_disco) / 2;

            for (int j = 0; j < espacos_laterais; j++) printf(" ");
            if (disco == 0) {
                for (int j = 0; j < largura_disco; j++)
                    printf(" ");
            } else {
                for (int j = 0; j < disco; j++) printf("*");
                printf("|");
                for (int j = 0; j < disco; j++) printf("*");
            }
            for (int j = 0; j < espacos_laterais; j++) printf(" ");
            printf("   ");
        }
        printf("\n");
    }

    printf("   T1                T2                T3\n\n");
}
