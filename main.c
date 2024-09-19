#include "menu.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleOutputCP(CP_UTF8);

    int qty = qtyItems();
    produto *arrayProdutos = import_data();
    menu(arrayProdutos, qty);

    free(arrayProdutos);
    return 0;
}