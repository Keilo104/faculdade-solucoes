# Faça um programa no qual o usuário digita um número N entre 1 e 15.
# Depois o programa deve criar e exibir uma lista com os N primeiros números primos.

nroP = int(input("Digite a quantidade(entre 1 e 15) de números primos desejados: "))
primos = []
contP = 0
contNro = 1

if 0 < nroP < 16:
    while contP != nroP:
        flagDivisivel = False
        contNro += 1

        for i in primos:
            if contNro % i == 0:
                flagDivisivel = True
                break

        if not flagDivisivel:
            primos += [contNro]
            contP += 1
    print(primos)
else:
    print("Não foi digitado um número entre 1 e 15")
