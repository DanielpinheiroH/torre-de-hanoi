#ifndef HANOI_H
#define HANOI_H

#include "pilha.h"
#include "lista_historico.h"

void iniciar_jogo(int num_discos);
void mover_disco(Pilha* origem, Pilha* destino);
int pode_mover(Pilha* origem, Pilha* destino);
void imprimir_pilhas_lado_a_lado(Pilha* t1, Pilha* t2, Pilha* t3, int max_altura);

#endif