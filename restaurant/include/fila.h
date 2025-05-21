#ifndef FILA_H
#define FILA_H

// Estrutura de nó de fila
typedef struct NoFila {
    int codigo_prato;
    struct NoFila *proximo;
} NoFila;

// Estrutura da fila
typedef struct {
    NoFila *frente;
    NoFila *tras;
} Fila;

// Inicializa a fila vazia
void inicializar_fila(Fila *fila);

// Enfileira um novo pedido
void enfileirar(Fila *fila, int codigo_prato);

// Desenfileira o pedido da frente
int desenfileirar(Fila *fila, int *codigo_prato);

// Exibe todos os pedidos em processamento
void listar_fila(const Fila *fila);

#endif // FILA_H