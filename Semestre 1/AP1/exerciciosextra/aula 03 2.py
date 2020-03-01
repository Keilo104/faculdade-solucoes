class Produto:
    def __init__(self):
        self.nome = ""
        self.preco = 0.0
        self.validade = ""


lista = []
menorPreco = 9999999
menorPrecoIdx = 0
cont = 0

while True:
    print("================MENU================")
    print("Digite uma opção:")
    print("1 - Cadastrar produto")
    print("2 - Listar produtos")
    print("3 - Exibir o item com menor preço")
    print("0 - Sair do programa")
    choice = int(input())

    if choice == 1:
        p = Produto()
        p.nome = input("Digite o nome do produto: ")
        p.preco = float(input("Digite o preço do produto: "))
        p.validade = input("Digite a validade do produto: ")
        lista += [p]

    elif choice == 2:
        for i in lista:
            print("Nome do produto: {}".format(i.nome))
            print("Preço do produto: {}".format(i.preco))
            print("Validade do produto: {}".format(i.validade))

    elif choice == 3:
        for i in lista:
            if i.preco < menorPreco:
                menorPreco = i.preco
                menorPrecoIdx = cont
            cont += 1

        print("O item mais barato é {} e custa {}.".format(lista[menorPrecoIdx].nome, lista[menorPrecoIdx].preco))

    elif choice == 0:
        break
