n = int(input("Digite a quantidade de números da série de Fibonacci desejados: "))

a = 0
b = 1
i = 0

while n > i:
    i += 1
    print("{}º número: {}".format(i, a))
    a, b = b, a + b
