#include "prodmanagement.h"

/**
 * \brief Adiciona um produto ao estoque.
 *
 * \param arrayProdutos com asterisco duplo significa que o ponteiro aponta para o ponteiro responsável pelo array de produtos.
 * \param qtd com asterisco significa que é o ponteiro responsável pela quantidade de produtos no estoque.
 *
 * \details Requisita ao usuário o nome do produto, sua quantidade e preço.
 *          Atribui o proximo ID disponivel ao produto.
 *          Realoca memoria para o vetor de produtos.
 *          Adiciona o produto ao vetor de produtos.
 *          Incrementa a quantidade de produtos no vetor.
 */
void addProduct(produto **arrayProdutos, int *qtd) {
    *arrayProdutos = realloc(*arrayProdutos, sizeof(produto) * (*qtd + 1));

    int nextID = (*qtd) + 1;
    char prodName[20];
    int quantidade;
    float price;

    printf("Nome do produto: ");
    fflush(stdin);
    fgets(prodName, sizeof(prodName), stdin);
    prodName[strcspn(prodName, "\n")] = 0;

    printf("Quantidade: ");
    fflush(stdin);
    scanf("%d", &quantidade);

    printf("Preço: ");
    fflush(stdin);
    scanf("%f", &price);

    (*arrayProdutos)[*qtd].id = nextID;
    strcpy((*arrayProdutos)[*qtd].name, prodName);
    (*arrayProdutos)[*qtd].quantity = quantidade;
    (*arrayProdutos)[*qtd].price = price;

    (*qtd)++;
}

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