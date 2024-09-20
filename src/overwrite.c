#include "overwrite.h"

void overwrite(produto *arrayProdutos, int qtd) {
    FILE *ptrStorage = fopen("database/storage.txt", "w");

    if (ptrStorage == NULL) {
        printf("Erro ao abrir o arquivo de estoque. Contate o administrador.\n");
        return;
    }
    
    for (int i = 0; i < qtd; i++) {
        fprintf(ptrStorage, "%d %s %d %.2f\n", arrayProdutos[i].id,
        arrayProdutos[i].name,
        arrayProdutos[i].quantity,
        arrayProdutos[i].price);
    }
    fclose(ptrStorage);
}