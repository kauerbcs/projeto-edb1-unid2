#include <stdio.h>
#include <stdlib.h>
#include "../include/fila.h"


/*Fila encadeada simples usada para gerenciar os pedidos que estão sendo 
processados na cozinha. Cada pedido contém o código do prato e um ponteiro 
para o próximo item na fila. A fila permite adicionar pedidos no final 
(enfileirar), remover o pedido que está na frente (desenfileirar) e listar 
os pedidos em processamento. A fila segue a lógica FIFO (o primeiro que 
entra é o primeiro que sai) e cresce dinamicamente conforme os pedidos 
são enviados para a cozinha.
*/

void inicializar_fila(Fila *fila) {
    fila->frente = fila->tras = NULL;
}

void enfileirar(Fila *fila, int codigo_prato) {
    NoFila *novo = malloc(sizeof(NoFila));
    if (!novo) return;
    novo->codigo_prato = codigo_prato;
    novo->proximo = NULL;
    if (!fila->tras) fila->frente = novo;
    else fila->tras->proximo = novo;
    fila->tras = novo;
}

int desenfileirar(Fila *fila, int *codigo_prato) {
    if (!fila->frente) return 0;
    NoFila *p = fila->frente;
    *codigo_prato = p->codigo_prato;
    fila->frente = p->proximo;
    if (!fila->frente) fila->tras = NULL;
    free(p);
    return 1;
}

void listar_fila(const Fila *fila) {
    NoFila *p = fila->frente;
    printf("Pedidos em processamento (cozinha):\n");
    
    if (!fila->frente) {
        printf("Nenhum pedido na fila.\n");
        return;
    }
    while (p) {
        printf(" - Codigo: %d\n", p->codigo_prato);
        p = p->proximo;
    }
}

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
