from typing import List


from os import system, name

# ***** B TREE *****


class BTreeNode:
    max = 4

    def __init__(self, value=None):
        if value == None:
            self.keys = []
        else:
            self.keys = Element(value)
        leaf = False

    def printBTree(BTreeNode):
        """ Chegar na folha mais a esquerda
                Imprimir todos os elementos dela
            Voltar para o pai
            Ir para a direita
                Imprimir todos os elementos
            Voltar para o pai


            Para cada elemento, chamar a função para esquerda
            E pela direita
            Se for o ultimo
            Fim

            Na função
         """
        for i in range(0, BTreeNode.keys.count):
            print(BTreeNode.keys[i].value)


class Element:
    def __init__(self, value):
        self.value = value
        self.branchLeft = BTreeNode()
        self.branchRight = BTreeNode()

# ***** FUNÇÕES AUXILIARES *****
#                   ** FORMAT **


def formatStr(string=str(), max=int(), fill=' '):
    if (len(string) < max):
        string = fill * max + string
    string = string[-max:]
    print(string)
    return string


def formatCode(code=str()):
    return formatStr(code, 8, '0')


def formatToWrite(l=[]):
    newList = []
    for i in l:
        newList.append(i + ';')
    newList.append('\n')
    return newList
#                   ** OUTROS **


def getProducts(filename="soy akivu.txt"):
    file = open(filename, 'r')
    products = file.readlines()
    return products


def getCode():
    return formatStr(str(int(input('Digite o codigo (apenas numeros): '))), 8, '0')


def newProd():
    l: List[str] = []
    l.append(getCode())
    l.append(formatStr(input('Digite o nome: '), 30, ' '))
    l.append(formatStr(str(float(input('Digite o preço: '))), 7, '0'))
    l.append(formatStr(
        input("Digite os ingredientes (separados por virgula ',' ): "), 150, ' '))
    l.append(formatStr(
        input("Digite as categorias (separadas por virgula ',' ): "), 80, ' '))
    l.append(formatStr(input('Digite se está disponivel [s/n] '), 1, ' '))
    return l


def searchCodeIn(prodCod=str(), prodList=[]):
    """
    procurar o produto na lista pelo codigo
    achar o codigo na linha
    verificar se eh o produto até chegar no final
    se sim
        retornar
    se não
        continuar

    """
    for i in range(len(prodList)):
        curCod = prodList[i][:8]
        if (curCod == prodCod):
            return i
    return -1


def clear():
    if(name == 'nt'):
        _ = system("cls")
    else:
        _ = system("clear")


def newGenericLine(lines=list()):
    codigo = '*' * 8
    lines.append(codigo + ';')
    nome = '*' * 30
    lines.append(nome + ';')
    preco = '*' * 7
    lines.append(preco + ';')
    ingredientes = '*' * 150
    lines.append(ingredientes + ';')
    categoria = '*' * 80
    lines.append(categoria + ';')
    disponivel = '*' * 1
    lines.append(disponivel + ';')
    lines.append('\n')

# ***** FUNÇÕES PRINCIPAIS *****


def printMenu():
    print("1 - Mostrar todos os produtos")
    print("2 - Mostrar um produto")
    print("3 - Adicionar produto")
    print("4 - Alterar produto")
    print("5 - Remover produto")
    print("0 - Sair")


def showAllProd():
    pass


def showProd(code=int()):
    products = getProducts()
    code = getCode()
    prod = searchCodeIn(code, products)
    if (prod != -1):
        print(prod)


def addProd(filename="soy akivu.txt"):
    file = open(filename, 'a')

    product = newProd()
    file.writelines(formatToWrite(product))

    file.close()


def changeProd(prodCod=str(), filename="soy akivu.txt"):
    prodCod = formatCode(prodCod)

    file = open(filename, 'r')
    products = file.readlines()
    prodLine = searchCodeIn(prodCod, products)
    if (prodLine != -1):  # produto encontrado
        print("produto encontrado")
        products[prodLine] = newProd()
        file = open(filename, 'w')
        print(products)
        file.writelines(products)
    else:
        print("produto não encontrado")
    file.close()


def removProd(filename="soy akivu.txt"):
    pass

    #   int *keys;  // An array of keys
    #   int t;      // Minimum degree (defines the range for number of keys)
    #   BTreeNode **C; // An array of child pointers
    #   int n;     // Current number of keys
    #   bool leaf; // Is true when node is leaf. Otherwise false


root = BTreeNode()
tree = BTreeNode()
tree2 = BTreeNode()

tree.keys.append(Element(5))

print(tree.keys[0].value)
print(tree2.keys)


"""
Alterar a linha do arquivo com a informação alterada
"""

"""
Escrever o codigo
escrever o nome
escrever os ingrdiente
escrever o valor
"""
#changeProd(input('digite codigo a trocar: '))

# **** MENU ****

"""
Perguntar o que quer fazer
Ver os produtos
Adicionar produto
Alterar produto
Remover produto
Sair
"""
op = ' '
while(op != '0'):
    printMenu()
    op = input('Digite a opção: ')
    if (op == '0'):  # Sair
        break
    elif(op == '1'):  # Mostrar todos produtos
        showAllProd()
    elif(op == '2'):  # Mostrar unico produto
        showProd()
    elif(op == '3'):  # Adicionar produto
        addProd()
    elif(op == '4'):  # Alterar produto
        changeProd()
    elif(op == '5'):  # Remover produto
        removProd()
    else:  # Opcao invalida
        pass
    clear()
