idade1 = int(input("Digite a idade da primeira pessoa: "))
idade2 = int(input("Digite a idade da segunda pessoa: "))
idade3 = int(input("Digite a idade da terceira pessoa: "))

idadeTot = idade1 + idade2 + idade3

if idadeTot >= 100:
    print("A idade total é maior ou igual que 100")
else:
    print("A idade total é menor que 100")
