#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"
#include "fila.h"

//asdasd

void exibir_menu() {
    printf("\n== Restaurante ==\n");
    printf("1. Adicionar pedido (salão)\n");
    printf("2. Remover pedido (salão)\n");
    printf("3. Processar próximo pedido (cozinha)\n");
    printf("4. Listar pendentes (salão)\n");
    printf("5. Listar em processamento (cozinha)\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

int main() {
    ListaPedido lista;
    Fila fila;
    int opcao, cod;

    inicializar_lista(&lista);
    inicializar_fila(&fila);

    do {
        exibir_menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Código do prato: ");
                scanf("%d", &cod);
                adicionar_pedido(&lista, cod);
                break;
            case 2:
                printf("Código a remover: ");
                scanf("%d", &cod);
                if (!remover_pedido(&lista, cod))
                    printf("Prato não encontrado.\n");
                break;
            case 3:
                if (transferir_para_fila(&lista, &cod)) {
                    enfileirar(&fila, cod);
                    printf("Pedido %d enviado para cozinha.\n", cod);
                } else printf("Nenhum pedido pendente.\n");
                break;
            case 4:
                listar_pedidos_pendentes(&lista);
                break;
            case 5:
                listar_fila(&fila);
                break;
        }
    } while (opcao != 0);

    return 0;
}