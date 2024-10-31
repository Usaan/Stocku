#include "listingprods.h"

void list_products(produto *arrayProdutos, int qtd) {
    printf("---------------------------------------------------------------\n");
    printf("%-10s%-19s%-10s%-10s\n", "ID", "Nome", "Qtd", "Preço");
    foreach (item, produto, qtd, arrayProdutos) {
        printf("%-10d%-19s%-10dR$%-10.2f\n",
        item->id,
        item->name,
        item->quantity,
        item->price);
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
    foreach (item, produto, qtd, arrayProdutos) {
        printf("%-10d%-19s%-10d\n",
        item->id,
        item->name,
        item->quantity);
    }
    printf("-----------------------------------------\n");
}