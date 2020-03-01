dia = int(input("Digite o dia atual: "))
mes = int(input("Digite o mês atual: ")) - 1

diasRest = 360 - (dia + (mes * 30))

print("Faltam {} dias para o ano acabar.".format(diasRest))