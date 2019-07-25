#include <stdio.h>
#include <stdlib.h>

/*
Pedir a primeira string
Pedir a segunda string
Buscar a segunda string na primeira
    Para cada letra da primeira string, comparar com a primeira da segunda até a segunda acabar
        usa um ponteiro pra o inicio da primeira string
        usa um outro ponteiro pra passar pela primeira string
        usa um outro ponteiro pra passar pela segunda string
        Salva a posição pra voltar depois
        Se for '\0'
            a string acabou e ela não estava
            sair do loop e retornar 0;
        Senão se for igual
            compara a proxima
        Senão se for diferente
            volta pra o inicio e passa pra a proxima letra da primeira string
*/

int main()
{
    char string1[100], string2[100];
    char *ptrLinear, *ptr1, *ptr2;

    printf("Digite a primeira string\n");
    scanf(" %[^\n]c",string1);
    printf("Digite a segunda string\n");
    scanf(" %[^\n]c",string2);

    //Inicia os ponteiros
    ptrLinear = string1;
    ptr1 = string1;
    ptr2 = string2;

    //Busca
    while(*ptrLinear != '\0' && *ptr2 != '\0') 
    {
        //É igual, e não chegou no final, proximo
        while(*ptr1 == *ptr2 && *ptr2 != '\0') {ptr1++; ptr2++;}
        
        //String encontrada
        if (*ptr2 == '\0') {}
        //Não encontrada, reseta e proximo
        else
        {
            ptr1 = ++ptrLinear;
            ptr2 = string2;
        }
    }

    //Dar resultado
    system("cls");
    if(*ptr2 == '\0') printf("\"%s\" ESTA em \"%s\"\n", string2, string1);
    else printf("\"%s\" NAO esta em \"%s\"\n", string2, string1);

    
    return 0;
}