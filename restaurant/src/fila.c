#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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
    while (p) {
        printf(" - Código: %d\n", p->codigo_prato);
        p = p->proximo;
    }
}