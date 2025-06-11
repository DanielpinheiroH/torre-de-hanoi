#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

void mostrar_historico() {
    FILE* arquivo = fopen("../dados/historico.txt", "r");
    if (!arquivo) {
        printf("Nenhum historico encontrado.\n");
        return;
    }

    char linha[200];
    printf("\n=== HISTORICO DE PARTIDAS ===\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
    printf("==============================\n\n");
}

int main() {
    int opcao, discos;

    do {
        printf("\n===== TORRE DE HANOI =====\n");
        printf("1 - Jogar\n");
        printf("2 - Ver historico\n");
        printf("3 - Sair\n");
        printf("===========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin); // evita erro de leitura com nome depois

        switch (opcao) {
            case 1:
                printf("Digite o numero de discos (minimo 3): ");
                scanf("%d", &discos);
                fflush(stdin);
                if (discos < 3) {
                    printf("Numero minimo de discos e 3.\n");
                } else {
                    iniciar_jogo(discos);
                }
                break;
            case 2:
                mostrar_historico();
                break;
            case 3:
                printf("Saindo do jogo...\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (1);

    return 0;
}