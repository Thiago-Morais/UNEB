from typing import List


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


def formatStr(string=str(), max=int(), fill=' '):
    if (len(string) < max):
        string = fill * max + string
    string = string[-max:]
    print(string)
    return string


def formatCode(code=str()):
    return formatStr(code, 8, '0')


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


def formatToWrite(l=[]):
    newList = []
    for i in l:
        newList.append(i + ';')
    newList.append('\n')
    return newList


def newProd():
    l: List[str] = []
    l.append(formatStr(str(int(input('Digite o codigo (apenas numeros): '))), 8, '0'))
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
changeProd(input('digite codigo a trocar: '))
