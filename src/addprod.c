#include "addprod.h"

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