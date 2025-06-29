#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hanoi.h"
#include "lista_historico.h"

extern void imprimir_pilhas_lado_a_lado(Pilha* t1, Pilha* t2, Pilha* t3, int max_altura);

void iniciar_jogo(int num_discos) {
    Pilha* t1 = criar_pilha();
    Pilha* t2 = criar_pilha();
    Pilha* t3 = criar_pilha();
    ListaHistorico* historico = criar_lista();

    char nome[50];
    printf("Digite seu nome: ");
    scanf(" %[^\n]", nome);

    for (int i = num_discos; i >= 1; i--) {
        empilhar(t1, i);
    }

    int origem, destino;
    int movimentos = 0;

    while (t2->tamanho != num_discos && t3->tamanho != num_discos) {
        imprimir_pilhas_lado_a_lado(t1, t2, t3, num_discos);
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
            printf("Movimento invalido!\n");
        }
    }

    imprimir_pilhas_lado_a_lado(t1, t2, t3, num_discos);
    printf("\n>>> Jogo concluido com sucesso! <<<\n");
    printf("Voce resolveu com %d movimentos.\n", movimentos);

    // Data/hora
    time_t agora = time(NULL);
    struct tm* tm_info = localtime(&agora);
    char data[30];
    strftime(data, sizeof(data), "%d/%m/%Y %H:%M:%S", tm_info);

    adicionar_registro(historico, nome, movimentos, num_discos, data);
    salvar_em_arquivo(historico, "../dados/historico.txt");

    liberar_pilha(t1);
    liberar_pilha(t2);
    liberar_pilha(t3);
    liberar_lista(historico);
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