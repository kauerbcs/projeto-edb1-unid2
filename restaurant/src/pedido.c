#include <stdio.h>
#include <stdlib.h>
#include "../include/pedido.h"
#include "../include/fila.h"
// Inicializa a lista de pedidos
void inicializar_lista(ListaPedido *lista) {
    lista->inicio = NULL;
    lista->contador_pedidos = 0;
}

// Cria um novo prato
Prato* criar_prato(int codigo_prato) {
    Prato *novo = malloc(sizeof(Prato));
    if (!novo) return NULL;
    novo->codigo_prato = codigo_prato;
    novo->proximo = NULL;
    return novo;
}

// Adiciona um novo pedido, contendo um ou mais pratos
void adicionar_pedido(ListaPedido *lista) {
    Pedido *novo = (Pedido *)malloc(sizeof(Pedido));
    novo->numero_pedido = ++(lista->contador_pedidos);
    novo->lista_pratos = NULL;
    novo->proximo = NULL;

    int codigo;
    do {
        printf("Digite o codigo do prato (0 para finalizar): ");
        scanf("%d", &codigo);
        
        if (codigo == 0) {
            break; // Sai do loop sem mostrar mensagem de erro
        }

        if (codigo > 0 && codigo <= 15) {
            Prato *prato = (Prato *)malloc(sizeof(Prato));
            prato->codigo_prato = codigo;
            prato->proximo = novo->lista_pratos;
            novo->lista_pratos = prato;
        } else {
            printf("Codigo invalido. Tente novamente.\n");
        }
    } while (1);

    // Inserir na lista de pedidos
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        Pedido *aux = lista->inicio;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }

    printf("Pedido %d adicionado.\n", novo->numero_pedido);
}


// Remove um pedido completo pelo número do pedido
int remover_pedido(ListaPedido *lista, int numero_pedido) {
    Pedido *atual = lista->inicio, *anterior = NULL;
    while (atual) {
        if (atual->numero_pedido == numero_pedido) {
            if (anterior) anterior->proximo = atual->proximo;
            else lista->inicio = atual->proximo;

            free(atual);
            printf("Pedido %d removido com sucesso!\n", numero_pedido);
            return 1;  // sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;  // pedido não encontrado
}
// Remove um prato específico de um pedido
// Retorna 1 se sucesso, 0 se não encontrou
int remover_prato_do_pedido(Pedido *pedido, int codigo_prato) {
    if (pedido == NULL) return 0;

    Prato *atual = pedido->lista_pratos;
    Prato *anterior = NULL;

    while (atual) {
        if (atual->codigo_prato == codigo_prato) {
            if (anterior == NULL) {
                // Primeiro prato da lista
                pedido->lista_pratos = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1;  // Sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;  // Prato não encontrado
}



// Retorna o ponteiro para o pedido se encontrado, ou NULL se não encontrado
// Busca um pedido pelo número do pedido, utilizando a lista de pedidos
Pedido* buscar_pedido(ListaPedido *lista, int numero_pedido) {
    Pedido *atual = lista->inicio;
    while (atual) {
        if (atual->numero_pedido == numero_pedido) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Retorna o ponteiro para o prato se encontrado, ou NULL se não encontrado
Prato* buscar_prato(Pedido *pedido, int codigo_prato) {
    Prato *atual = pedido->lista_pratos;
    while (atual) {
        if (atual->codigo_prato == codigo_prato) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Função que remove o primeiro pedido da lista
Pedido* retirar_primeiro_pedido(ListaPedido *lista) {
    
    // Se a lista estiver vazia, retorna NULL
    if (!lista->inicio) return NULL;

    // Armazena o primeiro pedido da lista para retorná-lo
    Pedido *pedido = lista->inicio;

    // Atualiza o ponteiro de início para o próximo pedido na lista
    lista->inicio = pedido->proximo;

    // Garante que o pedido removido não esteja mais vinculado à lista
    pedido->proximo = NULL;

    // Retorna o pedido removido para processamento posterior
    return pedido;
}



// Lista todos os pedidos e os pratos de cada pedido
void listar_pedidos(const ListaPedido *lista) {
    if (!lista->inicio) {
        printf("Nenhum pedido pendente.\n");
        return;
    }

    Pedido *p = lista->inicio;
    while (p) {
        printf("\nPedido %d:\n", p->numero_pedido);
        Prato *prato = p->lista_pratos;
        while (prato) {
            printf(" - Codigo do prato: %d\n", prato->codigo_prato);
            prato = prato->proximo;
        }
        p = p->proximo;
    }
}

// Libera toda a memória da lista de pedidos e seus pratos
void liberar_lista(ListaPedido *lista) {
    Pedido *p = lista->inicio;
    while (p) {
        Pedido *temp = p;
        p = p->proximo;

        Prato *prato = temp->lista_pratos;
        while (prato) {
            Prato *prato_temp = prato;
            prato = prato->proximo;
            free(prato_temp);
        }

        free(temp);
    }
    lista->inicio = NULL;
}