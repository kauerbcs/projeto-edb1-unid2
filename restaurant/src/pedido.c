#include <stdio.h>
#include <stdlib.h>
#include "../include/pedido.h"


/*Lista encadeada simples usada para armazenar os pedidos feitos no salão,
cada pedido contém o código do prato e um ponteiro para o próximo pedido.
A lista permite adicionar pedidos no final, remover pedidos específicos e
transferir o primeiro pedido para a fila de processamento (cozinha).
A lista cresce dinamicamente conforme os pedidos são adicionados.
*/
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
            printf("Pedido com codigo %d removido com sucesso!\n", codigo_prato);
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
    printf("Pedidos pendentes (salao):\n");
    if (!lista->inicio) {
        printf("Nenhum pedido pendente.\n");
        return;
    }
    while (p) {
        printf(" - Codigo: %d\n", p->codigo_prato);
        p = p->proximo;
    }
}
void liberar_lista(ListaPedido *lista) {
    Pedido *atual = lista->inicio;
    while (atual) {
        Pedido *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
}


