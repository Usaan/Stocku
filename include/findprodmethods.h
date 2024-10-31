#include "product.h"
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include "pretty.h"

int selected_product, selected_qty, ID;

produto* find_by_id(produto *arrayProdutos, int qtd);
produto* find_by_name(produto *arrayProdutos, int qtd);