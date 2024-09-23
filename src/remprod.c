#include "remprod.h"

void remProduct(produto **arrayProdutos, int *qtd) {
    bool idExists = false;
    int id;
    int idFound = 0;

    list_products_simple(*arrayProdutos, *qtd);
    printf("Digite o ID do produto que deseja remover: ");
    fflush(stdin);
    scanf("%d", &id);

    for (int i = 0; i < *qtd; i++) {
        if ((*arrayProdutos)[i].id == id) {
            idExists = true;
            idFound = i;
            break;
        }
    }

    if (idExists) {
        for (int j = idFound; j < *qtd - 1; j++) {
            (*arrayProdutos)[j] = (*arrayProdutos)[j + 1];
        }

        (*qtd)--;
        *arrayProdutos = realloc(*arrayProdutos, sizeof(produto) * (*qtd));
    }
}