dia = int(input("Digite o dia atual: "))
mes = int(input("Digite o mês atual: ")) - 1
diaNiver = int(input("Digite o dia do seu aniversário: "))
mesNiver = int(input("Digite o mês do seu aniversário: ")) - 1

diasRest = (diaNiver + (mesNiver * 30)) - (dia + (mes * 30))

if diasRest > 0:
    print("Faltam {} dias para o seu aniversário.".format(diasRest))
elif diasRest < 0:
    diasRest = diasRest + 360
    print("Faltam {} dias para o seu aniversário.".format(diasRest))
else:
    print("Hoje é seu aniversário!")
