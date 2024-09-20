#include "verifystorage.h"

int qty = 0;

/**
 * @brief Função que retorna a quantidade de itens no database.
 *
 * @details A função verifica se o diretório "database" existe, caso não exista, o mesmo é criado.
 * Abre o arquivo "database/storage.txt" em modo de leitura e conta quantas linhas ele tem, armazenando o valor na variável 
 * global "qty".
 *
 * @return Retorna o valor de "qty", que é a quantidade de itens no database.
 */
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
/**
 * @brief Função que importa os dados do database para um array de structs.
 *
 * @details A função abre o arquivo "database/storage.txt" em modo de leitura e aloca memória com o malloc
 * para um array de structs com o tamanho igual a quantidade de itens detectada.
 * Em seguida, lê as linhas do arquivo e armazena as informações em cada campo do array de structs.
 * Por fim, fecha o arquivo e retorna o array de structs.
 *
 * @return Um ponteiro para o array de structs >produto< com os dados do database.
 */
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