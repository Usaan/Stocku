#include "listingprods.h"
#include <stdlib.h>
#include <stdio.h>

void list_products(produto *arrayProdutos, int qtd) {
    printf("---------------------------------------------------------------\n");
    printf("%-10s%-19s%-10s%-10s\n", "ID", "Nome", "Qtd", "Preço");
    for (int i = 0; i < qtd; i++) {
        printf("%-10d%-19s%-10dR$%-10.2f\n",
        arrayProdutos[i].id,
        arrayProdutos[i].name,
        arrayProdutos[i].quantity,
        arrayProdutos[i].price);
    }
    printf("---------------------------------------------------------------\n");
    fflush(stdin);
    getchar();
    fflush(stdin);
    system("cls");
}
void list_products_simple(produto *arrayProdutos, int qtd) {
    printf("-----------------------------------------\n");
    printf("%-10s%-19s%-10s\n", "ID", "Nome", "Qtd");
    for (int i = 0; i < qtd; i++) {
        printf("%-10d%-19s%-10d\n",
        arrayProdutos[i].id,
        arrayProdutos[i].name,
        arrayProdutos[i].quantity);
    }
    printf("-----------------------------------------\n");
}