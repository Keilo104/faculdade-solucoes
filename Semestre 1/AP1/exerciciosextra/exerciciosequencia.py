# Leia o valor de N do usuário e calcule o valor da série:
# S = 2/4 - 3/9 + 4/16 – 5/25 + 6/36 - ... + n/m

n = int(input("Digite a quantidade de números na série desejados: "))
i = 0
s = 0

while n != i:
    i += 1
    if (i + 1) % 2 == 0:
        s = s + (i + 1) / ((i + 1) ** 2)
    else:
        s = s - (i + 1) / ((i + 1) ** 2)

print("O total da sequência com {} números é {}.".format(n, s))
