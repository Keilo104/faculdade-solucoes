bas = int(input("Digite a base da exponenciação: "))
exp = int(input("Digite o expoente da exponenciação: "))

res = 1

while exp > 0:
    res = res * bas
    exp = exp - 1
print("O resultado é {}.".format(res))
