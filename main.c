#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <locale.h>
#include "verifystorage.h"
#include "findprodmethods.h"

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

void menu(produto *arrayProdutos, int qtd) {

    int valid_option;
    int option;
    
    do {
        system("cls");
        printf("\n[1]. Listar produtos\t\t[2]. Adicionar produtos\n[3]. Remover produtos\t\t[4]. Buscar produtos\n[5]. Em breve...\t\t[0]. Sair\n");
        printf("\nEscolha uma opção: ");
        fflush(stdin);
        valid_option = scanf("%d", &option);

        if (valid_option != 1){

            system("cls");
            printf("\n Opção inválida! Pressione qualquer tecla para repetir.\n");
            fflush(stdin);
            getchar();
            system("cls");
        }
        else {
            switch (option) {
            case 1:
                system("cls");
                list_products(arrayProdutos, qtd);
                break;
            case 2:
                system("cls");
                list_products_simple(arrayProdutos, qtd);

                //Tratamento de exceções: Seleção de produtos.

                int valid_product;
                int valid_qty;

                while (valid_product){

                    printf("\nItem que deseja adicionar:\n");
                    valid_product = scanf("%d", &selected_product);

                    if (valid_product != 1) {

                        printf("\nOpção inválida! Tente novamente.\n");
                        fflush(stdin);
                    }
                    else if (selected_product < 1 || selected_product > 10){

                        printf("\nEsta numeração não corresponde a nenhum produto. Tente novamente.\n");
                    }
                    else {

                        //Tratamento de exceções: Quantidade de produtos.

                        while (valid_qty){

                            printf("\nQuantidade desejada: ");
                            valid_qty = scanf("%d", &selected_qty);

                            if (valid_qty != 1){

                                printf("\nOpção inválida! Tente novamente.\n");
                                fflush(stdin);
                            }
                            else if (selected_qty < 1 || selected_qty > 100){

                                printf("\nEsta numeração não é compatível. Tente novamente.\n");
                            }
                            else{ 
                                arrayProdutos[selected_product - 1].quantity += selected_qty;
                                system("cls");
                                printf("\nQuantidade acrescentada!\n");

                                Sleep(1000);
                                system("cls");
                                break; 
                                } 
                        }
                        break;
                        while (valid_qty != 0);
                    }  
                }
                break;
                while (valid_product != 0);
                
            case 3:
                system("cls");
                list_products_simple(arrayProdutos, qtd);

                //Tratamento de exceções: Remoção de produtos.

                int valid_remove;
                int valid_qty_remove;

                while (valid_remove){

                    printf("\nItem que deseja remover:\n");
                    valid_remove = scanf("%d", &selected_product);

                    if (valid_remove != 1){

                        printf("\nOpção inválida! Tente novamente.\n");
                        fflush(stdin);
                    }
                    else if (selected_product < 1 || selected_product > 10){

                        printf("\nEsta numeração não corresponde a nenhum produto. Tente novamente.\n");
                    }
                    else{

                        //Tratamento de exceções: Remoção de quantidade.

                        while (valid_qty_remove){

                            printf("\nQuantidade desejada: ");
                            valid_qty_remove = scanf("%d", &selected_qty);

                            if (valid_qty_remove != 1){

                                printf("\nOpção inválida! Tente novamente.\n");
                                fflush(stdin);
                            }
                            else if (selected_qty < 1 || selected_qty > 100){

                                printf("\nEsta numeração não é compatível. Tente novamente.\n");
                            }
                            else{ 
                                arrayProdutos[selected_product - 1].quantity -= selected_qty;
                                system("cls");
                                printf("\nQuantidade removida!\n");

                                Sleep(1000);
                                system("cls");
                                break; 
                                } 
                        }
                        break;
                        while (valid_qty_remove != 0);
                    }  
                }
                break;
                while (valid_remove != 0);

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
                            printf("\nNenhum item encontrado!\n");
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
                            printf("\nNenhum item encontrado!\n");
                        }

                        fflush(stdin);
                        getchar();
                        system("cls");
                        break;
                    default:
                        system("cls");
                        printf("\nOpção inválida! Pressione qualquer tecla para repetir.\n");
                        fflush(stdin);
                        getchar();
                        system("cls");
                        break;
                }
                system("cls");
                break;
            case 5:
                system("cls");
                printf("\nSe está lendo essa mensagem, significa que não deu tempo dessa função ser implementada :(\n");
                Sleep(5000);
                system("cls");
                break;
            case 0:
                system("cls");
                printf("\nEncerrando...\n");
                Sleep(1500);
                break;
            default:
                system("cls");
                printf("\nOpção inválida! Pressione qualquer tecla para repetir.\n");
                fflush(stdin);
                getchar();
                system("cls");
                break;
        }
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