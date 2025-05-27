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
    Pedido *pedido;
    int opcao, cod;

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
                printf("Codigo a remover: ");
                scanf("%d", &cod);
                if (!remover_pedido(&lista, cod))
                    printf("Pedido nao encontrado.\n");
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