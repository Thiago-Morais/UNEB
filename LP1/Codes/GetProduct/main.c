#include <stdio.h>
#include <stdlib.h>
#define debug(a) printf("%i\n", a)
/*
Pedir codigo do produto
Buscar pelo codigo no produos.txt
Pegar as informacoes do produto
Guardar em um struct produto
Guardar esse produto num carrinho
*/

typedef struct prod
{
    unsigned long cod;
    char name[100];
    float price;
}Prod;

typedef struct cart
{
    struct prod *content;
    struct cart *next;
}Cart;

Prod* GetProdByCod(FILE *fp, unsigned long cod)         //Procura um produto referente a um codigo passado, armazena as informações em
{
    /*

        Ler o primeiro undiggned long
        Comparar com cod
        Se for diferente
            Anda até o \n
            Anda mais um pra ficar no inicio da proxima linha
        Se for igual
            Pega as outras informações e guarda num prod novo
            retorna esse prod
    Se terminar e não achar, retorna NULL
    */

    Prod *product = (Prod*) malloc(sizeof(Prod));
    unsigned long codComp;

    fscanf(fp, "%lu", &codComp);    while(codComp != cod)
    {
        while(fgetc(fp) != '\n');
        fscanf(fp, "%lu", &codComp);
    }
    fscanf(fp, ";%[^;];%f\n", &product->name, &product->price);
    product->cod = codComp;

    //DEBUG
    //PrintProduct(product);
    //char prodDummy[100];
    //printf("1 == \n%lu \n%s \n%.2f\n", product->cod, product->name, product->price);

    //printf("\n%s\n",fgets(prodDummy, 100, fp));

    //while(fgetc(fp) != '\n');

    //printf("%c\n", fgetc(fp));
    return product;
}

Prod* GetProdInLine(FILE *fp)               //Pega as informações de um produto no inicio da linha, armazena num struct produto e retorna o ponteiro pra esser produto
{
    /*
    Cria um produto
    Cria um ponteiro pra esse produto
    Le Codigo, Nome e Preço nessa linha e guarda nos espaços do produto criado
    Retorna o ponteiro
    */
    Prod *product = (Prod*) malloc(sizeof(Prod));
    fscanf(fp, "%lu;%[^;];%f\n", &product->cod, &product->name, &product->price);
    printf("1 == %lu \n%s \n%.2f\n", product->cod, product->name, product->price);
    return product;
}

void PrintProduct(Prod *product)
{
    printf("\nProduct Code = %lu\n", product->cod);
    printf("Product Name = %s \n", product->name);
    printf("Product Price = %.2f\n", product->price);
}

int main()
{
    FILE *fp = fopen("produtos.txt", "r");
    Prod *cart = NULL;

    //GetProdInLine(fp);
    PrintProduct(GetProdByCod(fp,123654));

    //printf("%c\n", fgetc(fp));

    return 0;
}
