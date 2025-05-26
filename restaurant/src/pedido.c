#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"

void inicializar_lista(ListaPedido *lista) {
    lista->inicio = NULL;
}

void adicionar_pedido(ListaPedido *lista, int codigo_prato) {
    Pedido *novo = malloc(sizeof(Pedido));
    if (!novo) return;
    novo->codigo_prato = codigo_prato;
    novo->proximo = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        Pedido *p = lista->inicio;
        while (p->proximo) p = p->proximo;
        p->proximo = novo;
    }
}

int remover_pedido(ListaPedido *lista, int codigo_prato) {
    Pedido *atual = lista->inicio, *anterior = NULL;
    while (atual) {
        if (atual->codigo_prato == codigo_prato) {
            if (anterior) anterior->proximo = atual->proximo;
            else lista->inicio = atual->proximo;
            free(atual);
            return 1; // removido com sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // não encontrado
}

int transferir_para_fila(ListaPedido *lista, int *codigo_prato) {
    if (!lista->inicio) return 0;
    Pedido *p = lista->inicio;
    *codigo_prato = p->codigo_prato;
    lista->inicio = p->proximo;
    free(p);
    return 1;
}

void listar_pedidos_pendentes(const ListaPedido *lista) {
    Pedido *p = lista->inicio;
    printf("Pedidos pendentes (salão):\n");
    while (p) {
        printf(" - Código: %d\n", p->codigo_prato);
        p = p->proximo;
    }
}