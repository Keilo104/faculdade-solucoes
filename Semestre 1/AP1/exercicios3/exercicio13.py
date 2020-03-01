numcar = int(input("Digite a quantidade de carros vendidos: "))

modelomaisvalioso = ""
vlrmdl = 0
i = 0
soma = 0
numcar20a30 = 0
com = 0

while i != numcar:
    i += 1
    vlr = int(input("Digite o valor do {}º carro: ".format(i)))
    mdl = input("Digite o modelo do {}º carro: ".format(i))

    if vlr > vlrmdl:
        vlrmdl = vlr
        modelomaisvalioso = mdl

    if 20000 < vlr < 30000:
        numcar20a30 += 1

    if vlr > 10000:
        com = vlr * 0.11
    else:
        com = vlr * 0.10

    soma = soma + vlr

print("O vendedor receberá {} de comissão".format(com))
print("O modelo de carro mais caro é {}.".format(modelomaisvalioso))
print("A quantidade de carros que custam mais que R$20.000,00 e menos que R$30.000,00 é {}.".format(numcar20a30))
print("O preço médio dos carros é {}.".format(soma / numcar))
