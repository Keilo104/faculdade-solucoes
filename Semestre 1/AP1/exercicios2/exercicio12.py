a = int(input("Digite o primeiro lado do triângulo: "))
b = int(input("Digite o segundo lado do triângulo: "))
c = int(input("Digite o terceiro lado do triângulo: "))

if a < (b + c) and b < (a + c) and c < (a + b):
    if a == b and b == c:
        print("O triângulo é equilátero.")
    elif a == b or b == c or a == c:
        print("O triâgulo é isósceles.")
    else:
        print("O triângulo é escaleno.")
else:
    print("O triângulo não é válido.")