#include <stdio.h>
#include <stdlib.h>
#define debug(a) printf("check_%d\n", a)
#define prints(a) printf("%s\n", a);
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

typedef struct cartNode
{
    struct prod *content;
    struct cartNode *next;
}CartNode;

Prod* GetProdByCod(FILE *fp, unsigned long cod)         //Procura um produto referente a um codigo passado, armazena as informações em
{
    prints("GetProdByCod");
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
    {        while(fgetc(fp) != '\n');
        fscanf(fp, "%lu", &codComp);
    }

    fscanf(fp, ";%[^;];%f\n", product->name, &product->price);
    product->cod = codComp;

    //DEBUG
    //PrintProduct(product);
    //char prodDummy[100];
    //printf("1 == \n%lu \n%s \n%.2f\n", product->cod, product->name, product->price);

    //printf("\n%s\n",fgets(prodDummy, 100, fp));

    //while(fgetc(fp) != '\n');

    //printf("%c\n", fgetc(fp));
    rewind(fp);
    return product;
}

Prod* GetProdInLine(FILE *fp)               //Pega as informações de um produto no inicio da linha, armazena num struct produto e retorna o ponteiro pra esser produto
{
    prints("GetProdInLine");
    /*
    Cria um produto
    Cria um ponteiro pra esse produto
    Le Codigo, Nome e Preço nessa linha e guarda nos espaços do produto criado
    Retorna o ponteiro
    */
    Prod *product = (Prod*) malloc(sizeof(Prod));
    fscanf(fp, "%lu;%[^;];%f\n", &product->cod, product->name, &product->price);
    printf("1 == %lu \n%s \n%.2f\n", product->cod, product->name, product->price);
    return product;
}

void PrintProduct(Prod *product)
{
    prints("PrintProduct");
    printf("\nProduct Code = %lu\n", product->cod);
    printf("Product Name = %s \n", product->name);
    printf("Product Price = %.2f\n", product->price);
}

void AddProdInCart(Prod **prod, CartNode **cart)
{
    prints("AddProdInCart");
    /*
    Verificar se cart está vazio
    Senão
        Ir ate o final
    Inserir no final
    */
    CartNode *newContent = (CartNode*)malloc(sizeof(CartNode));
    newContent->next = NULL;
    newContent->content = prod;

    if(!*cart) *cart = newContent;
    else
    {
        CartNode *currentNode = *cart;

        while(currentNode->next != NULL) currentNode = currentNode->next;

        currentNode->next = newContent;
    }
}

void PrintCart(CartNode **cart)
{
    prints("PrintCart");

    if (!cart) return;

    CartNode *curNode = *cart;

    while(curNode != NULL)
    {
        PrintProduct(curNode->content);
        curNode = curNode->next;
    }

}

int main()
{
    FILE *fp = fopen("produtos.txt", "r");
    CartNode *cart = NULL;

    //GetProdInLine(fp);
    //PrintProduct(GetProdByCod(fp,123654));

    AddProdInCart(GetProdByCod(fp, 123654),&cart);
    AddProdInCart(GetProdByCod(fp, 456123),&cart);
    AddProdInCart(GetProdByCod(fp, 456123),&cart);
    AddProdInCart(GetProdByCod(fp, 456123),&cart);
    PrintCart(&cart);

    //printf("%c\n", fgetc(fp));

    return 0;
}
