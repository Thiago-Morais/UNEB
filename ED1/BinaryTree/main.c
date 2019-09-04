#include <stdio.h>
#include <stdlib.h>
#define COUNT 5
#define debug(a) printf("check_%d\n", a)

/*
Criar arvore
*/

typedef struct node
{
    int value;
    struct node *right;
    struct node *left;
}Node;

Node* NewNode (int value)
{
    Node *newLeaf = (Node*)malloc(sizeof(Node));

    newLeaf->value = value;
    newLeaf->right = NULL;
    newLeaf->left = NULL;
    return newLeaf;
}

void PrintTree(Node* in)
{
    printf("A arvore esta assim:\n");
    PrintLeafs(in, 0);
}
void PrintLeafs(Node* in, int space)
{
    if(!in) return;

    space += COUNT;

    PrintLeafs(in->right, space);

    //Imprimir com o espaço
    for(int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n", in->value);

    PrintLeafs(in->left, space);
}

short AddAsLeafIn(int value, Node** in)
{
    if(!*in)                            //Checar se a Arvore esta vazia
    {
        *in = NewNode(value);
        return 1;
    }

    if(value < (*in)->value)            //Se o valor é pra esquerda
        AddAsLeafIn(value, &(*in)->left);
    else                                //Se o valor é pra direita
        AddAsLeafIn(value, &(*in)->right);
    return 0;
}

Node* Remove(int value)
{
    /*
    Procurar pelo valor na arvore
    Se achar
        Verificar se ele tem filhos
        Remover o no
        Retornar o no
    Se não achar
        Retorna NULL
    */
}
int main()
{
    Node *root = NULL;
    int op = 999;

    while(op)
    {
        system("cls");
        printf("Digite a folha:");        scanf(" %d",&op);
        AddAsLeafIn(op, &root);
        PrintTree(root);        system("pause");
    }
    /*
    Node *root = NewNode(2);

    root->left = NewNode(1);
    root->right = NewNode(3);

    root->left->left = NewNode(4);
    */
    //PrintTree(root);

    return 0;
}
