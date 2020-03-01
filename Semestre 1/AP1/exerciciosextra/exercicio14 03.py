import random

i, par, impar, mnr30, maior, div4 = 0, 0, 0, 0, 0, 0

while True:
    i += 1

    # Faça um programa que gere números aleatórios entre 5 e 45
    n = random.randint(5, 45)
    print(n)

    # - o percentual de números pares e o percentual de números impares
    if n % 2 == 0:
        par += 1
    else:
        impar += 1

    # - a quantidade de números pares OU menores que 30 que foram gerados.
    if n < 30:
        if n % 2 == 0:
            mnr30 += 1
    else:
        # -  a quantidade de números divisíveis por 4 e maiores que 30 que foram gerados
        if n % 4 == 0:
            div4 += 1

    # - o maior número gerado
    if n > maior:
        maior = n

    # até gerar um número divisível por 7.
    if n % 7 == 0:
        break

porcentagemPar = (par / i) * 100
porcentagemImpar = (impar / i) * 100

# Quando isso ocorrer informar:
print("Foram gerados {} números divisíveis por 4 e maiores que 30.".format(div4))
print("Foram gerados {} números pares ou menores que 30.".format(mnr30))
print("{}% dos números digitados é par e {}% dos números digitados é ímpar.".format(porcentagemPar, porcentagemImpar))
print("{} foi o maior número gerado.".format(maior))
