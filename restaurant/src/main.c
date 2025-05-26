#include <stdio.h>
#include <stdlib.h>
#include "../include/pedido.h"
#include "../include/fila.h"




void exibir_menu() {
    printf("\n== Restaurante ==\n");
    printf("1. Adicionar pedido (salao)\n");
    printf("2. Remover pedido (salao)\n");
    printf("3. Processar proximo pedido (cozinha)\n");
    printf("4. Listar pendentes (salao)\n");
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
                printf("Codigo do prato: ");
                scanf("%d", &cod);
                adicionar_pedido(&lista, cod);
                break;
            case 2:
                printf("Codigo a remover: ");
                scanf("%d", &cod);
                if (!remover_pedido(&lista, cod))
                    printf("Prato nao encontrado.\n");
                break;
            case 3:
                if (transferir_para_fila(&lista, &cod)) {
                    enfileirar(&fila, cod);
                    printf("Pedido %d enviado para cozinha.\n", cod);
                } else {
                    printf("Nao ha proximos pedidos.\n");
                }
                break;
            case 4:
                listar_pedidos_pendentes(&lista);
                break;
            case 5:
                listar_fila(&fila);
                break;
        }
    } while (opcao != 0);

    liberar_fila(&fila);
    liberar_lista(&lista);
    return 0;
}