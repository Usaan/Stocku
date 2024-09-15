#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <locale.h>
#include "verifystorage.h"

int selected_product, selected_qty, ID;

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
void menu(produto *arrayProdutos, int qtd) {
    int option;
    do {
        system("cls");
        printf("[1]. Listar produtos\t\t[2]. Adicionar produtos\n[3]. Remover produtos\t\t[4]. Buscar produtos\n[5]. Em breve...\t\t[0]. Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                system("cls");
                list_products(arrayProdutos, qtd);
                break;
            case 2:
                system("cls");
                list_products_simple(arrayProdutos, qtd);

                printf("Item que deseja adicionar: ");
                scanf("%d", &selected_product);
                printf("Quantidade desejada: ");
                scanf("%d", &selected_qty);

                arrayProdutos[selected_product - 1].quantity += selected_qty;
                system("cls");
                printf("Quantidade acrescentada!\n");

                Sleep(1000);
                system("cls");
                break;
            case 3:
                system("cls");
                list_products_simple(arrayProdutos, qtd);

                printf("Item que deseja remover: ");
                scanf("%d", &selected_product);
                printf("Quantidade desejada: ");
                scanf("%d", &selected_qty);

                arrayProdutos[selected_product - 1].quantity -= selected_qty;
                system("cls");
                printf("Quantidade removida!\n");

                Sleep(1000);
                system("cls");
                break;
            case 4:
                system("cls");
                int option2;
                printf("[1]. Buscar pelo ID\t[2]. Buscar pelo Nome\n");
                printf("Escolha o algoritmo de busca: "); scanf("%d", &option2);

                switch (option2) {
                    case 1:
                        system("cls");
                        produto* test1 = find_by_id(arrayProdutos, qtd);
                        if (test1 != NULL) {
                            printf("-----------------------------------------\n");
                            printf("%-19s%-10s%-10s\n", "Nome", "Qtd", "Preço");	
                            printf("%-19s%-10dR$%-10.2f\n", test1->name, test1->quantity, test1->price);
                            printf("-----------------------------------------\n");
                        } else {
                            printf("Nenhum item encontrado!\n");
                        }
                        fflush(stdin);
                        getchar();
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        produto* test2 = find_by_name(arrayProdutos, qtd);
                        if (test2 != NULL) {
                            printf("-----------------------------------------\n");
                            printf("%-19s%-10s%-10s\n", "Nome", "Qtd", "Preço");	
                            printf("%-19s%-10dR$%-10.2f\n", test2->name, test2->quantity, test2->price);
                            printf("-----------------------------------------\n");
                        } else {
                            printf("Nenhum item encontrado!\n");
                        }

                        fflush(stdin);
                        getchar();
                        system("cls");
                        break;
                }
                system("cls");
                break;
            case 5:
                system("cls");
                printf("Se está lendo essa mensagem, significa que não deu tempo dessa função ser implementada :(\n");
                Sleep(5000);
                system("cls");
                break;
            case 0:
                system("cls");
                printf("Encerrando...\n");
                Sleep(1500);
                break;
            default:
                system("cls");
                printf("Opção inválida! Pressione qualquer tecla para repetir.\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
        }
    } while (option != 0);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleOutputCP(CP_UTF8);

    int qty = qtyItems();
    produto *arrayProdutos = import_data();
    menu(arrayProdutos, qty);

    free(arrayProdutos);
    return 0;
}