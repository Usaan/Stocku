#include "menu.h"

void menu(produto *arrayProdutos, int qtd) {

    int option;
    
    do {
        system("cls");
        printf("\n\t\t\t\t-- [ MENU INICIAL ] --\n");
        printf("\n[1] Cadastrar produtos\t\t[2] Listar produtos\t\t[3] Gerenciar estoque\n[4] Buscar produtos\t\t[5] Remover produtos\t\t[0] Sair\n");
        printf("\nEscolha uma opção: ");
        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
        case 1:
            system("cls");
            addProduct(&arrayProdutos, &qtd);
            overwrite(arrayProdutos, qtd);
            break;
        case 2:
            system("cls");
            fflush(stdin);
            list_products(arrayProdutos, qtd);
            break;
        case 3:
            system("cls");
            submenu(arrayProdutos, qtd);
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
            remProduct(&arrayProdutos, &qtd);
            overwrite(arrayProdutos, qtd);
            break;
        case 0:
            system("cls");
            printf("\nEncerrando...\n   ^---^\n  ( •ω• )\n o(  .  )o \n   U---U ");
            Sleep(2000);
            break;
        default:
            system("cls");
            printf("\nOpção inválida! Pressione qualquer tecla para repetir.\n");
            fflush(stdin);
            getchar();
            system("cls");
            break;
        }
    }while (option != 0);
}
void submenu(produto *arrayProdutos, int qtd) {
    int option;

    do {
        int cont = 0;
        system("cls");
        printf("\n\t\t\t\t --  [ ESTOQUE ] --\n");
        printf("\n[1] Adicionar produtos\t\t[2] Remover produtos\t\t[0] Voltar\n");
        printf("\nEscolha uma opção: ");
        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
            case 1:
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

                        printf("\nEsta numeração não corresponde a nenhum produto! Tente novamente.\n");
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

                                printf("\nEsta numeração não é compatível! Tente novamente.\n");
                            }
                            else{ 
                                arrayProdutos[selected_product - 1].quantity += selected_qty;
                                system("cls");
                                printf("\nQuantidade acrescentada!\n");

                                overwrite(arrayProdutos, qtd);
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
                break;
            case 2:
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

                        printf("\nEsta numeração não corresponde a nenhum produto! Tente novamente.\n");
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

                                printf("\nEsta numeração não é compatível! Tente novamente.\n");
                            }
                            else{ 
                                arrayProdutos[selected_product - 1].quantity -= selected_qty;
                                system("cls");
                                printf("\nQuantidade removida!\n");

                                overwrite(arrayProdutos, qtd);
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
            case 0:
                break;
            default:
                printf("\nOpção inválida! Pressione qualquer tecla para repetir.\n");
                fflush(stdin);
                getchar();
                break;
        }
    } while (option != 0);
}