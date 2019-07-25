#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//CODIGO PARA VERIFICAR SE UMA PALAVRA É UM PALINDROMO
/* 
    Pedir a string
    loop para comparar o primeiro e o ultimo algarismo
        se for igual continua
        senão se for diferente sai do laço
    quando saiu, verificar se saiu porque terminou igual
    ou se tava diferente
    dizer se foi um palindromo ou não
*/
int main()
{
    setlocale(LC_ALL, "portuguese");

    char entry[20];
    int i,j;
    char op = 'y';

    while (op == 'y')
    {
        printf("Digite um palindromo: ");
        scanf(" %[^\n]s", entry);

        printf("entry tem tamanho %d\n\n", strlen(entry));

        i = 0;
        j = strlen(entry)-1;

        while (i < j && entry[i] == entry[j])
        {
            i++;
            j--;
        }

        printf("\"%s\" ", entry);
        if(i >= j) printf("Eh um palindromo\n");
        else printf("Nao eh um palindromo\n\n");
        //system("pause");

        do
        {
            printf("Digitar outra palavra[y/n]: ");
            scanf(" %c", &op);
            //system("cls");
        } while(op != 'y' && op != 'n');
    }
    return 0;
}
