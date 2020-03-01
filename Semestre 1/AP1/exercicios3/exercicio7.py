n = int(input("Digite o valor de \"n\": "))

i = 0
m = 1
res = 0

while i != n:
    i += 1
    res = res + (i/m)
    m += 2
print("O resultado é {}.".format(res))