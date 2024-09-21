#include "addprod.h"

void addProduct() {
    int nextID = qtyItems() + 1;
    FILE *ptrStorage = fopen("database/storage.txt", "a");
    
    char prodName[20];
    int qtd;
    float price;

    printf("Nome do produto: ");
    fflush(stdin);
    fgets(prodName, sizeof(prodName), stdin);
    prodName[strcspn(prodName, "\n")] = 0;
    system("cls");
    printf("Quantidade: ");
    fflush(stdin);
    scanf("%d", &qtd);
    system("cls");
    printf("Preço: ");
    fflush(stdin);
    scanf("%f", &price);
    system("cls");

    fprintf(ptrStorage, "%d %s %d %.2f\n", nextID, prodName, qtd, price);

    fclose(ptrStorage);
}