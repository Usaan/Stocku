#include "remprod.h"

/**
 * \brief Remove um produto do estoque.
 *
 * \param arrayProdutos com asterisco duplo significa que o ponteiro aponta para o ponteiro responsável pelo array de produtos.
 * \param qtd com asterisco significa que é o ponteiro responsável pela quantidade de produtos no estoque.
 *
 * \details Requisita ao usuário o ID do produto a ser removido.
 *          Caso o ID exista, remove o produto do vetor e decrementa a quantidade de produtos, realocando a memória necessária.
 */
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