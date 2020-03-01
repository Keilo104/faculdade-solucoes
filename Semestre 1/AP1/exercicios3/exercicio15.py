num1 = int(input("Digite o número maior: "))
num2 = int(input("Digite o número menor: "))

i = num2
soma = 0

if i % 2 == 1:
    i += 1

while i < num1:
    print(i)
    soma += i
    i += 2
print("A soma de todos os números é {}".format(soma))
