#include <stdio.h>
#include "hanoi.h"

int main() {
    int discos;

    printf("===== Torre de Hanói =====\n");
    printf("Digite o número de discos: ");
    scanf("%d", &discos);

    iniciar_jogo(discos);

    return 0;
}