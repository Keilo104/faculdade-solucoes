lista = []

# Faça um programa que tenha um menu para gerenciar uma lista de números inteiros. O usuário pode escolher no menu as
# opções:
while True:
    print("=========MENU=========")
    print("Digite uma opção:")
    print("1: Cadastrar um número")
    print("2: Ordernar os números em ordem crescente")
    print("3: Verificar se um número existe na lista")
    print("4: Excluir um elemento da lista")
    print("0: Sair do Programa")

    comando = input()

    if comando == "0":
        print("Obrigado por usar o programa.")
        break

    elif comando == "1":
        numero = input("Digite o número a ser cadastrado: ")
        # numero = random.randint(0, 999)  # -> debug
        if numero not in lista:
            lista += [numero]
        else:
            print("Número já cadastrado.")

    elif comando == "2":
        listaCresT1 = lista.copy()
        menorAtual = 9999999999999
        for cont in lista:
            for i in listaCresT1:
                if i < menorAtual:
                    menorAtual = i
            print(menorAtual)
            listaCresT1.remove(menorAtual)
            menorAtual = 9999999999999

    elif comando == "3":
        check = int(input("Digite o número a ser verificado: "))
        flagCheck = False
        for i in lista:
            if i == check:
                flagCheck = True
        if flagCheck:
            print("Número {} está na lista.".format(check))
        else:
            print("Número não está cadastrado.")

    elif comando == "4":
        delete = int(input("Digite o número a ser deletado: "))
        flagDelete = False
        for i in lista:
            if i == delete:
                lista.remove(delete)
                flagDelete = True
        if flagDelete:
            print("Número {} foi deletado".format(delete))
        else:
            print("Item digitado não está na lista.")
