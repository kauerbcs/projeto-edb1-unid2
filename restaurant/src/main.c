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
void exibir_cardapio() {
    printf("\n=== CARDAPIO ===\n");

    printf("\nEntradas:\n");
    printf("1. Sopa de Cebola\n");
    printf("2. Salada Caesar\n");
    printf("3. Bruschetta\n");
    printf("4. Carpaccio de Carne\n");
    printf("5. Camarao ao Alho\n");

    printf("\nPratos Principais:\n");
    printf("6. Lasanha a Bolonhesa\n");
    printf("7. File Mignon com Fritas\n");
    printf("8. Frango Grelhado com Legumes\n");
    printf("9. Bacalhau a Gomes de Sa\n");
    printf("10. Risoto de Cogumelos\n");

    printf("\nSobremesas:\n");
    printf("11. Tiramisu\n");
    printf("12. Cheesecake de Frutas Vermelhas\n");
    printf("13. Mousse de Chocolate\n");
    printf("14. Pudim de Leite\n");
    printf("15. Sorvete de Baunilha com Calda de Morango\n");
}

int main() {
    ListaPedido lista;
    Fila fila;
    int opcao, codigo_prato, numero_pedido;
    Pedido *pedido;

    inicializar_lista(&lista);
    inicializar_fila(&fila);

    do {
        exibir_menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                exibir_cardapio();
                adicionar_pedido(&lista);
                break;
            case 2:
                printf("Numero do pedido: ");
                scanf("%d", &numero_pedido);

                // Verifica se o pedido existe
                pedido = buscar_pedido(&lista, numero_pedido);
                if (pedido == NULL) {
                    printf("Pedido nao encontrado!\n");
                    break;
                }

                printf("Codigo do prato para remover: ");
                scanf("%d", &codigo_prato);

                // Verifica se o prato existe no pedido
                Prato *prato = buscar_prato(pedido, codigo_prato);
                if (prato == NULL) {
                    printf("Prato nao encontrado neste pedido!\n");
                    break;
                }

                //Faz a remoção
                if (remover_prato_do_pedido(pedido, codigo_prato)) {
                    printf("Prato removido com sucesso!\n");
                    //  Pedido removido se não tiver mais pratos
                    // Verifica se o pedido ficou sem pratos
                    if (pedido->lista_pratos == NULL) {
                        printf("Pedido %d nao possui mais pratos e foi removido.\n", numero_pedido);
                        remover_pedido(&lista, numero_pedido);
                    }
                } else {
                    printf("Erro ao remover prato.\n");
                }
                break;

            case 3:
                pedido = retirar_primeiro_pedido(&lista);
                if (pedido) {
                    enfileirar(&fila, pedido);
                    printf("Pedido %d enviado para cozinha.\n", pedido->numero_pedido);
                } else {
                    printf("Nao ha proximos pedidos.\n");
                }
                break;
        
            case 4:
                listar_pedidos(&lista);
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