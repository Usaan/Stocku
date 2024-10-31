#ifndef MENU_H
#define MENU_H
#include "sleep.h"
#include "pretty.h"
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <locale.h>
#include "verifystorage.h"
#include "findprodmethods.h"
#include "listingprods.h"
#include "overwrite.h"
#include "prodmanagement.h"

void menu(produto *arrayProdutos, int qtd);

void submenu(produto *arrayProdutos, int qtd);

#endif