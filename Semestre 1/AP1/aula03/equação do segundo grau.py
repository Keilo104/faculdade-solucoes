import math

a = int(input("Digite o \"a\" da equação: "))
b = int(input("Digite o \"b\" da equação: "))
c = int(input("Digite o \"c\" da equação: "))

delta = (b ** 2) - (4 * a * c)

if delta < 0:
    print("Equação não tem raízes reais.")
else:
    x1 = (-b + math.sqrt(delta)) / (2 * a)
    if delta == 0:
        print("A equação tem apenas uma raiz, {}".format(x1))
    else:
        x2 = (-b - math.sqrt(delta)) / (2 * a)
        print("A equação tem raízes {} e {}".format(x1, x2))
