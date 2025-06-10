#ifndef PILHA_H
#define PILHA_H

typedef struct Nodo {
    int disco;
    struct Nodo *prox;
} Nodo;

typedef struct Pilha {
    Nodo *topo;
    int tamanho;
} Pilha;

Pilha* criar_pilha();
void empilhar(Pilha* pilha, int disco);
int desempilhar(Pilha* pilha);
int topo(Pilha* pilha);
int esta_vazia(Pilha* pilha);
void liberar_pilha(Pilha* pilha);
void imprimir_pilhas_lado_a_lado(Pilha* t1, Pilha* t2, Pilha* t3, int max_altura);

#endif