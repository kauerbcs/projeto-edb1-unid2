#ifndef FILA_H
#define FILA_H
#include "pedido.h"  // Importa a definição de Pedido

/*
Fila encadeada usada para gerenciar os pedidos em processamento na cozinha.
Cada nó da fila representa um pedido completo, com número único e lista de pratos.
A fila segue a lógica FIFO (First In, First Out) — o primeiro pedido que chega
é o primeiro a ser preparado.
*/

// Estrutura de nó da fila, que contém um pedido completo
typedef struct NoFila {
    Pedido *pedido;           // Ponteiro para o pedido
    struct NoFila *proximo;   // Próximo nó da fila
} NoFila;

// Estrutura da fila
typedef struct {
    NoFila *frente;           // Início da fila
    NoFila *tras;             // Fim da fila
} Fila;

// ==== Funções ====

// Inicializa a fila vazia
void inicializar_fila(Fila *fila);

// Enfileira um novo pedido na cozinha
void enfileirar(Fila *fila, Pedido *pedido);

// Desenfileira o pedido da frente
Pedido* desenfileirar(Fila *fila);

// Lista todos os pedidos em processamento (mostra número e pratos)
void listar_fila(const Fila *fila);

// Libera toda a memória alocada para a fila (mas não libera os pedidos!)
void liberar_fila(Fila *fila);

#endif // FILA_H
