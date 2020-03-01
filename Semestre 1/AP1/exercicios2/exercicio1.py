numero1 = int(input("Digite o primeiro número: "))
numero2 = int(input("Digite o segundo número: "))
numero3 = int(input("Digite o terceiro número: "))

if numero1 > numero2:
    if numero1 > numero3:
        print("{} é o maior número".format(numero1))
    else:
        print("{} é o maior número".format(numero3))
else:
    if numero2 > numero3:
        print("{} é o maior número".format(numero2))
    else:
        print("{} é o maior número".format(numero3))
