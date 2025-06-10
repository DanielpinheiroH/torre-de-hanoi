#ifndef LISTA_HISTORICO_H
#define LISTA_HISTORICO_H

typedef struct Registro {
    char nome[50];
    int movimentos;
    int discos;
    char data[20];  // dd/mm/yyyy HH:MM
    struct Registro* prox;
} Registro;

typedef struct {
    Registro* inicio;
} ListaHistorico;

ListaHistorico* criar_lista();
void adicionar_registro(ListaHistorico* lista, const char* nome, int movimentos, int discos, const char* data);
void salvar_em_arquivo(ListaHistorico* lista, const char* caminho);
void mostrar_historico(ListaHistorico* lista);
void buscar_por_nome(ListaHistorico* lista, const char* nome);
void liberar_lista(ListaHistorico* lista);

#endif