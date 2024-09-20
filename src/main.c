#include "menu.h"

/**
 * @brief Função o principal do programa.
 *
 * @param argc Numero mero de argumentos passados na linha de comando.
 * @param argv Vetor de strings com os argumentos passados na linha de comando.
 *
 * @return O valor de retorno do programa para o SO.
 *
 * @details A função seta o console de entrada e saida para o UTF-8, pega a quqantidade de itens no database e importa os 
 * dados dele para um array de structs. Em seguida, chama a função menu e finaliza o programa liberando a memória alocada.
 */
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleOutputCP(CP_UTF8);

    int qty = qtyItems();
    produto *arrayProdutos = import_data();
    menu(arrayProdutos, qty);

    free(arrayProdutos);
    return 0;
}