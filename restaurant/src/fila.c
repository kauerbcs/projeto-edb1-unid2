#include <stdio.h>
#include <stdlib.h>
#include "../include/fila.h"

/* Implementação de uma fila encadeada para gerenciar pedidos em processamento na cozinha.
Cada pedido contém uma lista de pratos, identificados por seus códigos, e um ponteiro
para o próximo pedido na fila
*/
// Inicializa a fila vazia
void inicializar_fila(Fila *fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

// Enfileira um pedido no final da fila
void enfileirar(Fila *fila, Pedido *pedido) {
    NoFila *novo = malloc(sizeof(NoFila));
    if (!novo) {
        printf("Erro: sem memoria para enfileirar\n");
        return;
    }
    novo->pedido = pedido;
    novo->proximo = NULL;

    if (fila->tras == NULL) {
        // fila vazia
        fila->frente = novo;
        fila->tras = novo;
    } else {
        fila->tras->proximo = novo;
        fila->tras = novo;
    }
}

// Desenfileira o pedido da frente, retornando o ponteiro para ele
Pedido* desenfileirar(Fila *fila) {
    if (fila->frente == NULL) return NULL;

    NoFila *temp = fila->frente;
    Pedido *pedido = temp->pedido;

    fila->frente = temp->proximo;
    if (fila->frente == NULL) fila->tras = NULL;

    free(temp);
    return pedido;
}

// Lista todos os pedidos na fila e seus pratos
void listar_fila(const Fila *fila) {
    NoFila *p = fila->frente;

    printf("Pedidos em processamento (cozinha):\n");
    if (!p) {
        printf("Nenhum pedido na fila.\n");
        return;
    }

    while (p) {
        printf(" - Pedido nº %d com pratos:\n", p->pedido->numero_pedido);

        // Percorre a lista de pratos do pedido
        Prato *prato = p->pedido->lista_pratos;
        while (prato) {
            printf("    * Código do prato: %d\n", prato->codigo_prato);
            prato = prato->proximo;
        }

        p = p->proximo;
    }
}

// Libera toda a memória dos nós da fila (não libera os pedidos)
void liberar_fila(Fila *fila) {
    NoFila *atual = fila->frente;
    while (atual) {
        NoFila *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    fila->frente = NULL;
    fila->tras = NULL;
}