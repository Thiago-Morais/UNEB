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
    unsigned long cod;                  //Codigo
    char name[100];                     //Nome
    float price;                        //Preço
}Prod;

typedef struct sale
{
    unsigned long productCode;          //Codigo do produto
    float price;                        //Preco total do conjunto
    size_t quantity;                    //Quantidade de produtos
    struct sale* next;
}Sale;

typedef struct cartNode
{
    struct prod *content;
    struct cartNode *next;
}CartNode;

Prod* GetProdByCod(FILE *filePointer, unsigned long cod)         //Procura um produto referente a um codigo passado, armazena as informações em
{
    prints("GetProdByCod");
    printf("\nCode = %d\n", cod);
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

    fscanf(filePointer, " %lu", &codComp);
    char aux;

    /*
    while(codComp != cod)                                   //Repete ate achar o codigo igual
    {
        while(fgetc(filePointer) != '\n');                      //Anda ate o final da linha
        fscanf(filePointer, " %lu", &codComp);                  //Depois pega o codigo na linha de baixo
    }
    */

    while(codComp != cod && aux != EOF)                     //Repete ate achar o codigo ou terminar o arquivo
    {
        do
        {
            aux = fgetc(filePointer);                               //anda um caracter
        }
        while(aux != '\n' && aux != EOF);                       //Anda ate o final da linha ou ate acabar o arquivo

        if(aux == EOF){rewind(filePointer); return NULL;}

        fscanf(filePointer, " %lu", &codComp);                  //Depois pega o codigo na linha de baixo
    }


    fscanf(filePointer, " ;%[^;];%f\n", product->name, &product->price);
    product->cod = codComp;

    rewind(filePointer);
    return product;
}

Prod* GetProdInLine(FILE *filePointer)               //Pega as informações de um produto no inicio da linha, armazena num struct produto e retorna o ponteiro pra esser produto
{
    prints("GetProdInLine");
    /*
    Cria um produto
    Cria um ponteiro pra esse produto
    Le Codigo, Nome e Preço nessa linha e guarda nos espaços do produto criado
    Retorna o ponteiro
    */
    Prod *product = (Prod*) malloc(sizeof(Prod));
    fscanf(filePointer, "%lu;%[^;];%f\n", &product->cod, product->name, &product->price);
    printf("1 == %lu \n%s \n%.2f\n", product->cod, product->name, product->price);

    rewind(filePointer);
    return product;
}

unsigned long GetCode()
{
    //Digite o codigo do produto
    system("cls");
    printf("======================================\n");
    printf("=                                    =\n");
    printf("=     DIGITE O CODIGO DO PRODUTO     =\n");
    printf("=                                    =\n");
    printf("======================================\n");

    unsigned long prodCod;
    scanf("%lu", &prodCod);
    return prodCod;
}

size_t GetQuantity()
{
    //Digite a quantidade
    system("cls");
    printf("======================================\n");
    printf("=                                    =\n");
    printf("=   DIGITE A QUANTIDADE DO PRODUTO   =\n");
    printf("=                                    =\n");
    printf("======================================\n");

    size_t prodQuant;
    scanf("%u", &prodQuant);

    return prodQuant;
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

    if(!*cart) *cart = newContent;                                              //Carrinho vazio, adiciona no inicio
    else                                                                        //Tem coisa no carrinho
    {
        CartNode *currentNode = *cart;

        while(currentNode->next != NULL) currentNode = currentNode->next;           //Anda ate o final

        currentNode->next = newContent;                                             //Coloca no final
    }
}

void AddSale(Prod *product, size_t quantity, Sale **start)
{
    prints("AddProdSaleCart");
    /*
    Pedir um codigo
    Procurar pelo produto
    Validar o produto
    Guardar o produto
    Guardar o codigo do produto no Node

    Pedir a quantidade
    Guardar a quantidade no Node

    Multiplicar a quantidade pelo preço
    Guardar o preço no Node

    Adicionar esse node a uma lista
    */
    Sale *newSet = (Sale*)malloc(sizeof(Sale));
    /*
    unsigned long code;
    Prod *product;

    code = GetCode();
    product = GetProdByCod(filePointer, code);
    */
    newSet->productCode = product->cod;
    newSet->quantity = quantity;    newSet->price = product->price * quantity;    newSet->next = NULL;
    /*
    newSet->productCode = code;
    newSet->quantity = GetQuantity();
    newSet->price = product->price * newSet->quantity;
    newSet->next = NULL;
    */
    if(!*start) *start = newSet;                                              //Carrinho vazio, adiciona no inicio
    else                                                                        //Tem coisa no carrinho
    {
        Sale *currentSale = *start;

        while(currentSale->next != NULL) currentSale = currentSale->next;           //Anda ate o final

        currentSale->next = newSet;                                             //Coloca no final
    }
}

Sale* RemoveSale(Sale **cart)
{
    /*
    Pedir o codigo do produto a ser removido
    Procurar o produto no carrinho pelo codigo
        Pegar um produto no carrinho
        Comparar o codigo com o do produto
        Se o codigo for igual
            Retirar ele
        Se o codigo for diferente
            Ir para o proximo produto
    Remover o produto do carrinho
    */
    unsigned long cod = GetCode();

    if(!*cart)
    {
        printf("\nCarrinho vazio\n");
        system("pause");
        return NULL;
    }

    Sale *currentSale = *cart, *prev = NULL;

    while(currentSale && currentSale->productCode != cod)
    {
        prev = currentSale;
        currentSale = currentSale->next;
    }

    if(!currentSale)
    {
        prints("Codigo do produto nao esta no carrinho");
        system("pause");
        return;
    }
    else        //Retirar
    {
        //Se estiver no começo
        if(currentSale == *cart)
        {
            prev = currentSale;
            *cart = currentSale->next;
        }
        //Se estiver no meio ou no final
        else
            prev->next = currentSale->next;

        system("pause");
        return(currentSale);
    }

}
void PrintProduct(Prod *product)
{
    prints("PrintProduct");

    if(!product)
    {
        prints("Produto nao existe");
        return;
    }

    printf("\nProduct Code = %lu\n", product->cod);
    printf("Product Name = %s \n", product->name);
    printf("Product Price = %.2f\n", product->price);
}
void PrintSaleNode(Sale *node)
{
    prints("SaleNode");

    if(!node)
    {
        prints("Sale nao existe");
        system("pause");
        return;
    }

    printf("\nProduct Code = %lu\n", node->productCode);
    printf("Product Amount = %u \n", node->quantity);
    printf("Total Value = %.2f\n", node->price);
}
void PrintCart(CartNode **cart)
{
    system("cls");
    prints("PrintCart");

    if (!*cart)
    {
        prints("Carrinho vazio");
        system("pause");
        return;
    }

    CartNode *curNode = *cart;
    while(curNode != NULL)
    {
        PrintProduct(curNode->content);
        curNode = curNode->next;
    }
    system("pause");
}

void PrintSale(Sale **start)
{
    system("cls");
    prints("PrintSale");

    if (!*start)
    {
        prints("Carrinho vazio");
        system("pause");
        return;
    }

    Sale *curNode = *start;
    while(curNode != NULL)
    {
        PrintSaleNode(curNode);
        curNode = curNode->next;
    }
    system("pause");
}

void PrintSellMenu()
{
    system("cls");
    printf("======================================\n");
    printf("=                                    =\n");
    printf("=           MENU DE VENDAS           =\n");
    printf("=                                    =\n");
    printf("= - SELECIONE UMA OPCAO              =\n");
    printf("=                                    =\n");
    printf("= 1 - MOSTRAR O CARRINHO             =\n");
    printf("= 2 - ADICIONAR PRODUTO AO CARRINHO  =\n");
    printf("= 3 - REMOVER PRODUTO DO CARRINHO    =\n");
    printf("= 0 - FINALIZAR A COMPRA             =\n");
    printf("=                                    =\n");
    printf("======================================\n");
}

int main()
{
    FILE *filePointer = fopen("produtos.txt", "r");
    CartNode *cart = NULL;
    Sale *saleCart = NULL;
    char op = '1';

    /*
    char aux;

    while(aux != '\n' && aux != EOF)
    {
        aux = fgetc(filePointer);
        printf("aux = (%c)\n", aux);
    }

    if(aux == EOF) debug(1);
    else if(aux == '\n') debug(2);
    else debug(3);

    printf("%d\n", aux);
    printf("%d\n", EOF);
    system("pause");
    */

    while(op != 0)                                                      //Update
    {
        system("cls");

        PrintSellMenu();

        fflush(stdin);        scanf(" %d", &op);
        fflush(stdin);
        /*
        printf("%d\n", op);
        system("pause");
        */
        switch (op)
        {
            case '1':     //mostrar carrinho
            {
                //mostrar carrinho
                //PrintCart(&cart);
                PrintSale(&saleCart);
                break;
            }
            case '2':     //adicionar produto ao carrinho
            {
                char validation = 'n';
                unsigned long tempCod;
                Prod *tempProd = NULL;

                while(validation == 'n')                                //Ciclo de validação do produto
                {
                    system("cls");
                    tempProd = GetProdByCod(filePointer, GetCode());        //Pede um codigo de produto e procura ele por esse codigo

                    if(tempProd)                                            //Se o produto foi encontrado
                    {
                        system("cls");
                        PrintProduct(tempProd);                                 //Mostra o produto

                        printf("\nEsse eh o produto? (y/n)");                   //Pede confirmação
                        scanf(" %c",&validation);

                        while(validation != 'n' && validation != 'y')              //Se digitar algo não permitido
                        {
                            system("cls");
                            printf("Opcao invalida\n");                                 //Informa o erro
                            system("pause");

                            system("cls");
                            PrintProduct(tempProd);                                     //Mostra o produto de novo

                            printf("\nEsse eh o produto? (y/n)");                       //Pede confirmação de novo
                            scanf(" %c",&validation);
                        }
                    }
                    else                                                    //Se o produto não foi encontrado
                    {
                        system("cls");
                        prints("\nCodigo Invalido\n");
                        system("pause");
                    }
                }
                //AddProdInCart(GetProdByCod(filePointer, GetCode()), &cart);
                //AddProdInCart(tempProd, &cart);
                AddSale(tempProd, GetQuantity(), &saleCart);
                break;
            }
            case '3':     //remover produto do carrinho
            {
                RemoveSale(&saleCart);
                break;
            }
            case '0':     //sair
            {
                break;
            }
            default:    //opção invalida
            {
                system("cls");
                prints("\nOpcao invalida\n");
                system("pause");
                break;
            }
        }
    }

    return 0;
}
