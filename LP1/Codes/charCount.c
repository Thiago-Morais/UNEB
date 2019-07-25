#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    char c;
    int count = 0;

    printf("Digite uma frase: ");
    scanf("%[^\n]s", string);

    printf("Escolha uma letra para procurar na frase: ");
    scanf(" %c", &c);

    for (size_t i = 0; i < strlen(string); i++)
    {
        if (string[i] == c) count++;
    }
    
    printf("a letra \"%c\" aparece %d vezes na frase \"%s\"", c, count, string);

    return 0;
}