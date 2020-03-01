flagMaisCaro = False
flagOrdenado = False
lista = []
listaPreco = []
maisCaro = 0
maisCaroNome = ""
cont = 0

while True:
    print("=========MENU=========")
    print("Escolha uma das opções abaixo:")
    print("1: Cadastrar produto.")
    print("2: Verificar produto mais caro")
    print("3: Verificar quais produtos é maior que \"x\"")
    print("4: Listar itens por ordem crescente de valor")
    print("0: Sair do programa")
    choice = input()

    if choice == "1":
        lista += [input("Digite o nome do produto a ser cadastrado: ")]
        listaPreco += [int(input("Digite o preço do produto: "))]
        # x = randint(0, 999)
        # lista += [x]
        # listaPreco += [x]
        flagMaisCaro = False
        flagOrdenado = False

    if choice == "2":
        if flagMaisCaro:
            print("[] é o produto mais caro.".format(maisCaroNome))
        else:
            cont = 0
            for elemento in listaPreco:
                if elemento > maisCaro:
                    maisCaro = elemento
                    maisCaroNome = lista[cont]
                cont += 1
            flagMaisCaro = True
            print("{} é o produto mais caro.".format(maisCaroNome))

    if choice == "3":
        cont = 0
        precoMin = int(input("Digite o preço mínimo desejado: "))
        for elemento in listaPreco:
            if elemento > precoMin:
                print(lista[cont])
            cont += 1

    if choice == "4":
        if flagOrdenado:
            for elemento in listaPrecoOrd:
                print(lista[listaPreco.index(elemento)])

        else:
            listaPrecoOrdT = listaPreco.copy()
            listaPrecoOrd = []
            menorAtual = 9999999999999

            for cont in lista:
                for i in listaPrecoOrdT:
                    if i < menorAtual:
                        menorAtual = i
                listaPrecoOrd += [menorAtual]
                listaPrecoOrdT.remove(menorAtual)
                menorAtual = 9999999999999
            flagOrdenado = True

            for elemento in listaPrecoOrd:
                print(lista[listaPreco.index(elemento)])

    if choice == "0":
        print("Obrigado por usar o programa")
        break
