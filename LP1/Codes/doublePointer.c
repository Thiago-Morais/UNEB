#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int value;
    struct nodo* next;
}Nodo;


void AddTo(int value, Nodo** start)
{

}

int main()
{
    Nodo* head = NULL;
    Nodo* sec = NULL;
    Nodo* thir = NULL;

    head = (Nodo*) malloc(sizeof(Nodo));
    sec = (Nodo*) malloc(sizeof(Nodo));
    thir = (Nodo*) malloc(sizeof(Nodo));

    head->next = sec;
    sec->next = thir;
    thir->next = NULL;

    head->value = 1;
    sec->value = 2;
    thir->value = 3;

    /* printf("%d\n",head);
    printf("%d\n",&head->value);

    printf("\nVariavel\n");
    printf("%d\n", head);
    printf("%d\n", sec);
    printf("%d\n", thir);

    printf("\nEndereco\n");
    printf("%d\n", &head);
    printf("%d\n", &sec);
    printf("%d\n", &thir);

    printf("\nO que aponta\n");
    printf("%d\n", *head);
    printf("%d\n", *sec);
    printf("%d\n", *thir);

    printf("\nValores\n");
    printf("%d\n", head->value);
    printf("%d\n", sec->value);
    printf("%d\n", thir->value);

    printf("\nEnderecos dos Valores\n");
    printf("%d\n", &head->value);
    printf("%d\n", &sec->value);
    printf("%d\n", &thir->value);

    printf("\nProximos\n");
    printf("%d\n", head->next);
    printf("%d\n", sec->next);
    printf("%d\n", thir->next);
    
    printf("\nEndereco dos Proximos\n");
    printf("%d\n", &head->next);
    printf("%d\n", &sec->next);
    printf("%d\n", &thir->next);
    
    printf("\nPonteiros dos Proximos\n");
    printf("%d\n", *head->next);
    printf("%d\n", *sec->next);
    //printf("%d\n", *thir->next); 
    */

   int v[3] = {1,2,3};
   int *point;

   point = v;

   printf("%d\n", v);
   printf("%d\n", *point);
   printf("%d\n", *++point);
   printf("%d\n", *point);

    return 0;
}