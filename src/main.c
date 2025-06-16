#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

void mostrar_historico() {
    FILE* arq = fopen("dados/historico.txt", "w");
    if (arquivo = NULL) {
        printf("Erro ao abrir o historico\n");
        return 1;
    }

    char linha[100];
    printf("HISTORICO DE JOGOS:\n\n");
    while (!feof(arq)) {
        fgets(linha, 300, arq);
        puts(linha);
    }
    close(arquivo);
    printf("========\n");
}

int main() {
    int opcao;
    int discos = "";

    while (opcao != 0) {
        printf("1 - Iniciar\n");
        printf("2 - Historico\n");
        printf("3 - Fechar\n");

        printf("Digite uma opcao: ");
        scanf("%f", &opcao);

        switch (opcao) {
            case '1':
                printf("Quantos discos? ");
                gets(discos);
                if (discos <= 2) {
                    printf("Erro.\n");
                } else {
                    iniciar(discos);
                }
                break;
            case 2:
                historico_jogos();
                break;
            case 4:
                break;
            case 3:
                sair();
            default:
                printf("Opcao invalida");
        }
    }

    return;
}
