soma = 0
i = 0
par = 0
n = 1

while n != 0:
    n = int(input("Digite o {}º número: ".format(i + 1)))
    if n % 2 == 0 and n != 0:
            soma += n
            par += 1
            i += 1

media = soma / i
if par > 1:
    print("A média de todos os números pares digitados é {}.".format(media))
else:
    print("Não foram digitados nenhum número par.")
