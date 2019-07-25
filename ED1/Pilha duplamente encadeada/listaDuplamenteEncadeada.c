#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    struct nodo* prev;
    int value;
    struct nodo* next;
}Nodo;

void AddOrderedIn(int value, Nodo **start)
{
    Nodo *novo, *aux;

    novo = (Nodo*) malloc(sizeof(Nodo));

    aux = *start;

    while(aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = novo;
    novo->prev = aux;
    novo->value = value;

}

void PrintMenu()
{
    system("cls");
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*  Digite um numero para selecionar uma opcao  *\n");
    printf("*  1 - Imprimir Lista                          *\n");
    printf("*  2 - Adicionar na lista                      *\n");
    printf("*  3 - Retirar da Lista                        *\n");
    printf("*  0 - Sair                                    *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
}

void PrintList(Nodo **start)
{
    system("cls");
    printf("lista\n");
    system("pause");
}

int GetValue()
{
    int value;
    system("cls");
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*  Digite um numero para selecionar uma opcao  *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
    scanf(" %d", &value);
    return value;
}

void GetMenuInput()
{
    
}

int main()
{
    Nodo *start;
    Nodo *sec;
    char op = '1';

    start = (Nodo*) malloc(sizeof(Nodo));
    sec = (Nodo*) malloc(sizeof(Nodo));

    while(op != '0')
    {
        PrintMenu();
        scanf(" %c", &op);
        switch (op)
        {
            case '1':   //Imprimir Lista
                PrintList(&start);
                break;
            case '2':   //Adicionar na lista
                AddOrderedIn(GetValue(), &start);
                break;
            case '3':   //Retirar da Lista
                break;
            default:
                break;
        }
    }

    start->value = 6;
    sec->value = 9;

    start->next = sec;
    sec->next = NULL;

    start->prev = NULL;
    sec->prev = start;


    printf("%d\n",start->value);
    printf("%d\n",sec->value);
    printf("%d\n",(sec->next)->value);

    return 0;
}
