#ifndef PRODUCT_H
#define PRODUCT_H
typedef struct Produto {
    int id;
    char name[20];
    int quantity;
    float price;
} produto;
int selected_product, selected_qty, ID;
#endif