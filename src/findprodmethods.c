#include "findprodmethods.h"

/**
 * \brief Busca um produto pelo seu ID.
 *
 * \param arrayProdutos Vetor de produtos.
 * \param qtd Quantidade de produtos no vetor.
 *
 * \returns Um ponteiro para o produto encontrado ou NULL se n o existir.
 */
produto* find_by_id(produto *arrayProdutos, int qtd) {
    printf("ID do item que deseja buscar: ");
    scanf("%d", &ID);

    foreach (item, produto, qtd, arrayProdutos){
        if (equal(item->id, ID)) {
            return item;
        }
    }
    return NULL;

    fflush(stdin);
    getchar();
    system("cls");
}

/**
 * \brief Busca um produto pelo seu nome.
 *
 * \param arrayProdutos Vetor de produtos.
 * \param qtd Quantidade de produtos no vetor.
 *
 * \returns Um ponteiro para o produto encontrado ou NULL se n o existir.
 */
produto* find_by_name(produto *arrayProdutos, int qtd) {
    char tempSearch[20];

    printf("Nome do item que deseja buscar: ");
    fflush(stdin);
    // fgets é uma função que vai ler o que o usuário digitar e colocar dentro de tempSearch
    fgets(tempSearch, sizeof(tempSearch), stdin);
    // remove o \n do final da string (tratamento necessário para evitar erros de leitura)
    tempSearch[strcspn(tempSearch, "\n")] = 0;
    system("cls");
    // busca pelo nome comparando o nome do arrayProdutos[i] com o nome tempSearch e imediatamente retorna o resultado
    foreach (item, produto, qtd, arrayProdutos){
        if (equal(item->name, tempSearch)) {
            return item;
        }
    }
    // caso não encontre, retorna NULL (já que um ponteiro precisa ser retornado pela função)
    return NULL;
}