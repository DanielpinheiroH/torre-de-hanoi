#ifndef LISTA_HISTORICO_H
#define LISTA_HISTORICO_H

// Estrutura de um registro de histórico de jogo
typedef struct Registro {
    char nome[50];
    int movimentos;
    int discos;
    char data[30];
    struct Registro* prox;
} Registro;

// Lista ligada de registros
typedef struct {
    Registro* inicio;
} ListaHistorico;

// Funções públicas da lista de histórico
ListaHistorico* criar_lista();
void adicionar_registro(ListaHistorico* lista, const char* nome, int movimentos, int discos, const char* data);
void salvar_em_arquivo(ListaHistorico* lista, const char* caminho_arquivo);
void liberar_lista(ListaHistorico* lista);

#endif