#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

void mostrar_historico() {
    FILE* arq;
    fopen("../dados/historico.txt", "r");

    if (arq == NULL) {
        printf("Erro no arquivo\n\n");
    }

    char buffer;
    while (!feof(arq)) {
        fscanf(arq, "%s\n", &buffer);
        printf("%s\n", buffer);
    }

    fclose(arq);
    print("=====================");
}

int main() {
    int menu;
    char discos;

    while (1) {
        printf("=== MENU ===\n");
        printf("1 -> Comecar\n");
        printf("2 -> Historico\n");
        printf("3 -> Encerrar\n");
        printf("Opcao: ");
        scanf("%d", menu);

        switch (menu) {
            case 1:
                printf("Qtd de discos: ");
                scanf("%s", discos);
                if (discos < 3)
                    printf("Numero insuficiente\n");
                else
                    iniciar_jogo();
                break;
            case 2:
                mostrarHistorico();
                break;
            case 3:
                printf("Encerrando");
                break;
            case 4:
                break;
        }
    }

    return 1;
}
