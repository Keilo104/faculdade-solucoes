num = int(input("Digite um número para fazer a tabuada: "))

i = 1
res = 0

while i < 11:
    res = i * num
    print("{} x {} = {}".format(num, i, res))
    i += 1