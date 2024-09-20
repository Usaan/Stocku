#include "verifystorage.h"

int qty = 0;

int qtyItems(){
    mkdir("database");
    FILE *ptrStorage = fopen("database/storage.txt", "r");
    if (ptrStorage == NULL) {
        ptrStorage = fopen("database/storage.txt", "w");
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), ptrStorage) != NULL) {
        qty++;
    }
    fclose(ptrStorage);
    return qty;
}
produto *import_data() {
    FILE *ptrStorage = fopen("database/storage.txt", "r");
    produto *arrayProdutos = malloc(sizeof(produto) * qty);

    for (int i = 0; i < qty; i++) {
        fscanf(ptrStorage, "%d %19s %d %f", 
        &arrayProdutos[i].id,
        arrayProdutos[i].name,
        &arrayProdutos[i].quantity,
        &arrayProdutos[i].price);
    }
    fclose(ptrStorage);
    return arrayProdutos;
}