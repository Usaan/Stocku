#include "findprodmethods.h"
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>

produto* find_by_id(produto *arrayProdutos, int qtd) {
    printf("ID do item que deseja buscar: ");
    scanf("%d", &ID);
    system("cls");

    for (int i = 0; i < qtd; i++) {
        if (arrayProdutos[i].id == ID) {
            return &arrayProdutos[i];
        }
    }
    return NULL;
}

produto* find_by_name(produto *arrayProdutos, int qtd) {
    char tempSearch[20];

    printf("Nome do item que deseja buscar: ");
    fflush(stdin);
    fgets(tempSearch, sizeof(tempSearch), stdin);
    tempSearch[strcspn(tempSearch, "\n")] = 0;
    system("cls");

    for (int i = 0; i < qtd; i++) {
        if (strcmp(arrayProdutos[i].name, tempSearch) == 0) {
            return &arrayProdutos[i];
        }
    }
    return NULL;
}