i = 0
prataCaro = 0
prataCaroNome = ""
mais60k = 0
amarelo2010 = 0
amarelo2010media = 0
branco30k = 0

while True:
    i += 1
    modelo = input("Digite o modelo do {}º carro: ".format(i))               # Faça um programa para informatizar o
    ano = int(input("Digite o ano de fabricação do {}º carro: ".format(i)))  # cadastro de carros em um estacionamento.
    valor = float(input("Digite o valor do {}º carro: ".format(i)))          # Você deve cadastrar os carros com as seguintes
    cor = input("Digite a cor do {}º carro: ".format(i))                     # informações: modelo, ano de fabricação, valor e cor.
    print("---------------------------------------------")

    if valor > prataCaro and cor == "prata":              # - o modelo do carro mais caro e da cor prata.
        prataCaro = valor
        prataCaroNome = modelo

    if cor == "preto" and (valor > 60000 or ano < 2017):  # - a quantidade de carros pretos com valor maior que
        mais60k += 1                                      # R$ 60.000,00 ou ano de fabricação menor que 2017

    if cor == "amarelo" and ano > 2010:                   # - média de valores dos carros amarelos com ano de
        amarelo2010 += 1                                  # fabricação maior que 2010.
        amarelo2010media += valor

    if cor == "branco" and valor > 30000:                 # - o percentual de carros que custam mais que
        branco30k += 1                                    # R$ 30.000,00 e que são da cor branca.

    if ano < 2000:                                        # Devem ser cadastrados carros até algum veículo com ano
        break                                             # de fabricação inferior a 2000 ser cadastrado.

# Quando isso ocorrer informar:

# - o modelo do carro mais caro e da cor prata.
if prataCaro == 0:
    print("Nenhum carro prata foi cadastrado.")
else:
    print("O carro prata mais caro cadastrado era modelo \"{}\", valendo R${}.".format(prataCaroNome, prataCaro))

# - a quantidade de carros pretos com valor maior que R$ 60.000,00 ou ano de fabricação menor que 2017
print("Foram cadastrados {} carros pretos com valor maior que R$60.000,00 ou com ano de fabricação menor que 2017.".format(mais60k))

# - média de valores dos carros amarelos com ano de fabricação maior que 2010.
if amarelo2010 == 0:
    print("Não foram cadastrados carros amarelos com ano de fabricação maior que 2010.")
else:
    amarelo2010media = amarelo2010media / amarelo2010
    print("A média de valor entre os carros amarelos com ano de fabricação maior que 2010 é R${}.".format(amarelo2010media))

# - o percentual de carros que custam mais que R$ 30.000,00 e que são da cor branca.
mediaBranco30k = (branco30k / i) * 100
print("{}% dos carros cadastrados custam mais de R$30.000,00 e são da cor branca.".format(mediaBranco30k))
