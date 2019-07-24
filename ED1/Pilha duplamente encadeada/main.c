#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    struct nodo* prev;
    int value;
    struct nodo* next;
}Nodo;

void Add(Nodo **start, int value)
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

int main()
{
    Nodo *start;
    Nodo *sec;

    start = (Nodo*) malloc(sizeof(Nodo));
    sec = (Nodo*) malloc(sizeof(Nodo));

    start->value = 6;
    sec->value = 9;

    start->next = sec;
    sec->next = NULL;

    start->prev = NULL;
    sec->prev = start;

    Add(&start, 45);

    printf("%d\n",start->value);
    printf("%d\n",sec->value);
    printf("%d\n",(sec->next)->value);

    return 0;
}
