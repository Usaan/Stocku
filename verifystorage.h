typedef struct Produto {
    int id;
    char name[20];
    int quantity;
    float price;
} produto;

produto* import_data();
int qtyItems();

