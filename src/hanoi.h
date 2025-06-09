#ifndef HANOI_H
#define HANOI_H

#include "pilha.h"

void iniciar_jogo(int num_discos);
void mover_disco(Pilha* origem, Pilha* destino);
int pode_mover(Pilha* origem, Pilha* destino);
void exibir_torres(Pilha* t1, Pilha* t2, Pilha* t3);

#endif