#include "overwrite.h"

void overwrite(produto *arrayProdutos, int qtd) {
    // FILE *ptrStorage = fopen("database/storage.txt", "w");

    //if (ptrStorage == NULL) {
    //    printf("Erro ao abrir o arquivo de estoque. Contate o administrador.\n");
    //    return;
    //}

    with (ptrStorage, fclose, fopen("database/storage.txt", "w")){
        foreach (item, produto, qtd, arrayProdutos) {
            fprintf(ptrStorage, "%d %s %d %.2f\n",
            item->id,
            item->name,
            item->quantity,
            item->price);
        }
    }
}