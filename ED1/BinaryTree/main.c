#include <stdio.h>
#include <stdlib.h>
#define COUNT 5
#define debug(a) printf("check_%d\n", a)

/*
Criar arvore
*/

typedef struct branch
{
    int value;
    struct branch *right;
    struct branch *left;
}Branch;

Branch* NewBranch (int value)
{
    Branch *newLeaf = (Branch*)malloc(sizeof(Branch));

    newLeaf->value = value;
    newLeaf->right = NULL;
    newLeaf->left = NULL;
    return newLeaf;
}

void PrintBranch(Branch* in)
{
    printf("A arvore esta assim:\n");
    PrintLeafs(in, 0);
}
void PrintLeafs(Branch* in, int space)
{
    if(!in) return;

    space += COUNT;

    PrintLeafs(in->right, space);

    //Imprimir com o espaço
    for(int i = COUNT; i < space; i++) printf(" ");
    printf("%d---\n", in->value);

    PrintLeafs(in->left, space);
}

short AddAsLeafIn(int value, Branch** in)
{
    if(!*in)                            //Checar se a Arvore esta vazia
    {
        *in = NewBranch(value);
        return 1;
    }

    if(value < (*in)->value)            //Se o valor é pra esquerda
        AddAsLeafIn(value, &(*in)->left);
    else                                //Se o valor é pra direita
        AddAsLeafIn(value, &(*in)->right);
    return 0;
}

Branch* Remove(Branch** root, int value)
{
    /*
    Procurar pelo valor na arvore
    Se achar (removeBranch)
        Verificar se ele tem filhos
        Se não tiver
            Remover o no
            Retornar o no
        Se tiver
            Procurar pelo menor do maior (substituto)
                Anda um galho a direita
                Anda pela esquerda ate nao poder mais
            Substituir removeBranch por substituto
                Copiar nos a esquerda e direita de removeBranch e colocar em substituto
                O no que aponta para removeBranch agora aponta substituto
            Retornar removeBranch
    Se não achar
        Retorna NULL
    */
    /*

    */
    if(!*root) return NULL;

    Branch *seek = *root, *prev = NULL;

    while (seek->value != value)
    {
        prev = seek;
        seek = seek->left;
    }
}
int main()
{
    Branch *root = NULL;
    int op = 999;

    while(op)
    {
        system("cls");
        printf("Digite a folha a adicionar na arvore:");        scanf(" %d",&op);
        AddAsLeafIn(op, &root);
        PrintBranch(root);        system("pause");
    }
    /*
    Branch *root = NewBranch(2);

    root->left = NewBranch(1);
    root->right = NewBranch(3);

    root->left->left = NewBranch(4);
    */
    //PrintBranch(root);

    return 0;
}
