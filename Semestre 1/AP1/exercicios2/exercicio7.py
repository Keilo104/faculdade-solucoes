salario = float(input("Digite o salário do funcionário: "))
prest = float(input("Digite o valor da prestação desejada: "))

maxPres = salario * 0.3

if prest > maxPres:
    print("O funcionário não pode pedir a prestação.")
else:
    print("O funcionário pode pedir a prestação.")
