#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

void iniciar_jogo(int num_discos) {
    Pilha* t1 = criar_pilha();
    Pilha* t2 = criar_pilha();
    Pilha* t3 = criar_pilha();

    for (int i = num_discos; i >= 1; i--) {
        empilhar(t1, i);
    }

    int origem, destino;
    int movimentos = 0;

    while (t3->tamanho != num_discos) {
        exibir_torres(t1, t2, t3);
        printf("Movimento #%d\n", movimentos + 1);
        printf("Digite origem (1, 2 ou 3): ");
        scanf("%d", &origem);
        printf("Digite destino (1, 2 ou 3): ");
        scanf("%d", &destino);

        Pilha *p1 = origem == 1 ? t1 : origem == 2 ? t2 : t3;
        Pilha *p2 = destino == 1 ? t1 : destino == 2 ? t2 : t3;

        if (pode_mover(p1, p2)) {
            mover_disco(p1, p2);
            movimentos++;
        } else {
            printf("Movimento inválido!\n");
        }
    }

    printf("Parabéns! Você resolveu com %d movimentos.\n", movimentos);

    liberar_pilha(t1);
    liberar_pilha(t2);
    liberar_pilha(t3);
}

void mover_disco(Pilha* origem, Pilha* destino) {
    int disco = desempilhar(origem);
    empilhar(destino, disco);
}

int pode_mover(Pilha* origem, Pilha* destino) {
    if (esta_vazia(origem)) return 0;
    if (esta_vazia(destino)) return 1;
    return topo(origem) < topo(destino);
}

void exibir_torres(Pilha* t1, Pilha* t2, Pilha* t3) {
    printf("\n=== ESTADO DAS TORRES ===\n");
    imprimir_pilha(t1, 1);
    imprimir_pilha(t2, 2);
    imprimir_pilha(t3, 3);
    printf("=========================\n\n");
}