#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    struct nodo* prev;
    int value;
    struct nodo* next;
}Nodo;

void AddIn(int value, Nodo **start)
{
    Nodo *novo, *current;

    novo = (Nodo*) malloc(sizeof(Nodo));
    novo->next = NULL;
    novo->prev = NULL;
    novo->value = value;

    if(*start == NULL)
    {
        *start = novo;
        return;
    }

    current = *start;
    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = novo;
    novo->prev = current;
}

void AddOrderedIn(int value, Nodo **start)
{
    Nodo *novo, *current;

    novo = (Nodo*) malloc(sizeof(Nodo));
    novo->next = NULL;
    novo->prev = NULL;
    novo->value = value;

    if(*start == NULL)
    {
        *start = novo;
        return;
    }

    current = *start;
    while(current->next != NULL && current->next->value < value)
    {
        current = current->next;
    }
    if(current->next == NULL)
    {
        current->next = novo;
        novo->prev = current;
    }
    else
    {
        if (current->prev != NULL)
        {
            current->prev->next = novo;
            novo->prev = current->prev;
        }
        current->prev = novo;
        novo->next = current;
    }

    /*
    if(current->next != NULL)
    {
        current->next->prev = novo;
        novo->next = current->next;
    }
    current->next = novo;
    novo->prev = current;
    */
        /*
        if(current->prev == NULL)
        {
            current->prev = novo;
            novo->next = current;
        }

        else
        {
            curren->prev->next = novo;
            novo->prev = curren->prev;
            novo->next = current;
            current->prev = novo;
        }*/

    /*
    if(current->prev == NULL)
    {
        current->prev = novo;
    }
    current->next = novo;
    novo->prev = current
    */
}

/*


*/

void PrintList(Nodo **start)
{
    Nodo *current = *start;

    while (current != NULL)
    {
        printf("%d ",current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Nodo *start = NULL;
    //Nodo *sec;

    //start = (Nodo*) malloc(sizeof(Nodo));
    //sec = (Nodo*) malloc(sizeof(Nodo));

    //start->value = 6;
    //sec->value = 9;

    //start->next = NULL;
    //start->next = sec;
    //sec->next = NULL;

    //start->prev = NULL;
    //sec->prev = start;

    PrintList(&start);
    AddOrderedIn(77, &start);
    PrintList(&start);
    AddOrderedIn(72, &start);
    PrintList(&start);
    AddOrderedIn(64, &start);
    PrintList(&start);
    AddOrderedIn(68, &start);
    PrintList(&start);
    AddOrderedIn(55, &start);
    PrintList(&start);
    AddOrderedIn(15, &start);
    PrintList(&start);
    AddOrderedIn(75, &start);
    PrintList(&start);
    AddOrderedIn(35, &start);
    PrintList(&start);
    AddOrderedIn(74, &start);
    PrintList(&start);
    /*
    printf("%d\n",start->value);
    printf("%d\n",sec->value);
    printf("%d\n",(sec->next)->value);
    */

    return 0;
}
