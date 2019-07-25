#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
    pedir o anagrama
    pedir a palavra
    comparar os tamanhos das duas palavras
        se o tamanho for igual
            loop
                somar os caracteres do anagrma
                somar os caracteres da palavra
            se os resultados forem iguais
                dizer que é um anagrama
            senão
                dizer que não é um anagrama
        se o tamanho for diferente 
            dizer que não é um anagrama
 */

int main()
{
    char anagram[100];
    char comparer[100];
    int content1 = 0, content2 = 0;
    int size;

    system("cls");
    printf("Digite uma palavra para comparar com o anagrama: ");
    scanf(" %s", comparer);
    system("cls");

    printf("Digite o anagrama: ");
    scanf(" %s", anagram);
    system("cls");


    size = strlen(anagram);
    if(size == strlen(comparer))
    {
        for (size_t i = 0; i < size; i++)
        {
            content1 += anagram[i];
            content2 += comparer[i];
        }

        if(content1 == content2) 
            printf("\"%s\" eh um anagrama para \"%s\"", anagram, comparer);
        else 
            printf("\"%s\" NAO eh um anagrama para \"%s\"", anagram, comparer);
    }
    else
    {
        printf("\"%s\" NAO eh um anagrama para \"%s\"", anagram, comparer);
    }
    
    return 0;
}