#ifndef PEDIDO_H
#define PEDIDO_H

// Estrutura que representa um item de pedido
typedef struct Pedido {
    int codigo_prato;        // Código do prato conforme cardápio
    struct Pedido *proximo;  // Próximo pedido na lista
} Pedido;

// Cabeça da lista de pedidos pendentes
typedef struct {
    Pedido *inicio;
} ListaPedido;

// Inicializa a lista ligada
void inicializar_lista(ListaPedido *lista);

// Adiciona um novo prato ao final da lista
void adicionar_pedido(ListaPedido *lista, int codigo_prato);

// Remove um prato específico (pelo código) da lista
int remover_pedido(ListaPedido *lista, int codigo_prato);

// Transfere um pedido (cabeça) para a fila de processamento
int transferir_para_fila(ListaPedido *lista, int *codigo_prato);

// Exibe todos os pedidos pendentes na lista
void listar_pedidos_pendentes(const ListaPedido *lista);

#endif // PEDIDO_H