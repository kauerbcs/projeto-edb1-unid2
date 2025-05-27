#ifndef PEDIDO_H
#define PEDIDO_H

/*
Lista encadeada dupla onde cada nó representa um pedido.
Cada pedido possui:
    - Um número único (numero_pedido).
    - Uma lista de pratos (que também é uma lista encadeada).
Isso permite que um pedido tenha vários pratos associados.
*/

// Estrutura que representa um prato dentro de um pedido
typedef struct Prato {
    int codigo_prato;         // Código do prato conforme cardápio
    struct Prato *proximo;    // Próximo prato na lista
} Prato;

// Estrutura que representa um pedido
typedef struct Pedido {
    int numero_pedido;        // Número único do pedido
    Prato *lista_pratos;      // Lista de pratos do pedido
    struct Pedido *proximo;   // Próximo pedido na lista
} Pedido;

// Estrutura da lista de pedidos pendentes
typedef struct {
    Pedido *inicio;           // Ponteiro para o primeiro pedido
    int contador_pedidos;     // Contador para gerar número único dos pedidos
} ListaPedido;

// Inicializa a lista de pedidos
void inicializar_lista(ListaPedido *lista);

//remove um prato específico de um pedido

int remover_prato_do_pedido(Pedido *pedido, int codigo_prato);


//busca um pedido pelo número do pedido
Pedido* buscar_pedido(ListaPedido *lista, int numero_pedido);

// Busca um prato específico dentro de um pedido
Prato* buscar_prato(Pedido *pedido, int codigo_prato);


// Retira o primeiro pedido da lista, retornando o ponteiro para ele
Pedido* retirar_primeiro_pedido(ListaPedido *lista);

// Cria um novo pedido, permitindo adicionar vários pratos a ele
void adicionar_pedido(ListaPedido *lista);

// Remove um pedido específico pelo número do pedido
int remover_pedido(ListaPedido *lista, int numero_pedido);

// Lista todos os pedidos e os pratos de cada pedido
void listar_pedidos(const ListaPedido *lista);

// Libera toda a memória alocada para a lista de pedidos e seus pratos
void liberar_lista(ListaPedido *lista);

#endif // PEDIDO_H
