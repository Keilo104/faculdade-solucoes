lista1 = []
lista2 = []
flagUniao = False
flagL2 = False

while True:
    print("===========MENU===========")
    print("Escolha uma opção abaixo: ")
    print("1 - Inserir um item na lista 1.")
    print("2 - Inserir itens na lista 2.")
    print("3 - Exibir o conteúdo da lista 1 e 2.")
    print("4 - Criar e exibir uma lista(ListaUniao) com elementos de ambas as listas.")
    print("5 - Exibir uma lista com elementos comuns entre ambas as listas.")
    print("6 - Somar o maior valor dentro de uma lista a todos os itens da primeira lista.")
    print("7 - Exibir uma lista com os valores da primeira multiplicados pelos valores da segunda.")
    print("8 - Resetar ambas as listas")
    print("9 - Ordenar a ListaUniao em ordem decrescente (apenas possível caso a ListaUniao exista).")
    print("0 - Sair do programa.")
    choice = int(input())

    if choice == 0:
        print("Obrigado por usar o programa.")
        break

    elif choice == 1:
        if len(lista1) < 5:
            inserir = int(input("Digite o número a ser inserido na lista 1: "))
            lista1 += [inserir]
            flagUniao = False
        else:
            print("Lista 1 já tem 5 elementos.")

    elif choice == 2:
        if flagL2:
            print("Lista 2 já tem 5 elementos.")
        else:
            inserir = int(input("Digite o número a ser inserido na lista 2: "))
            for i in range(0, 5):
                lista2 += [inserir * (2 ** i)]
            flagUniao = False
            flagL2 = True

    elif choice == 3:
        print(lista1)
        print(lista2)

    elif choice == 4:
        listaUniao = []

        for i in lista1:
            listaUniao += [i]
        for i in lista2:
            listaUniao += [i]

        print(listaUniao)
        flagUniao = True

    elif choice == 5:
        listaExc = []
        tamanho = len(lista2)

        for i in range(0, tamanho):
            if lista2[i] in lista1:
                listaExc += [lista2[i]]
        print(listaExc)

    elif choice == 6:
        maiorLista = 0
        cont = 0

        for i in lista1:
            if i > maiorLista:
                maiorLista = i
        for i in lista2:
            if i > maiorLista:
                maiorLista = i

        for i in lista1:
            nro = i + maiorLista
            lista1.remove(i)
            lista1.insert(cont, nro)
            cont += 1

        flagUniao = False
        print("Maior item numa lista é {}.".format(maiorLista))
        print(lista1)

    elif choice == 7:
        listaMult = []
        tamanho = len(lista1)

        if lista2:
            for i in range(0, tamanho):
                listaMult += [lista1[i] * lista2[i]]

        print(listaMult)

    elif choice == 8:
        lista1 = []
        lista2 = []
        flagUniao = False
        flagL2 = False
        print("Todas as listas foram resetadas.")

    elif choice == 9:
        if flagUniao:
            lUnDcrsTemp = listaUniao.copy()
            lUnDecresc = []

            for i in listaUniao:
                maiorAtual = 0

                for elemento in lUnDcrsTemp:
                    if elemento > maiorAtual:
                        maiorAtual = elemento
                lUnDecresc += [maiorAtual]
                lUnDcrsTemp.remove(maiorAtual)

            print(lUnDecresc)

        else:
            print("ListaUniao não existe ou está desatualizada, por favor, utilize opção 4.")
