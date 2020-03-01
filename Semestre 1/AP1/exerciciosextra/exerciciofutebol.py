i = 0
contCor80kg = 0
cor80kg = 0
mnr20 = 0
maisNovo = 127
maisNovoNome = ""
sant20ou65 = 0

while True:
    i += 1
    # Faça um programa para informatizar o cadastro dos jogadores de futebol em um time. Você deve cadastrar os
    # jogadores com as seguintes informações: nome, idade, peso e time.
    nome = input("Digite o nome do {}º jogador: ".format(i))
    idade = int(input("Digite a idade do {}º jogador: ".format(i)))
    peso = float(input("Digite o peso do {}º jogador: ".format(i)))
    time = input("Digite o time do {}º jogador: ".format(i))

    # média de idade dos jogadores do “corinthians” com mais de 80 quilos.
    if time == "corinthians" and peso > 80:
        contCor80kg += 1
        cor80kg += idade

    # o percentual de jogadores que tem menos de 20 anos
    if idade < 20:
        mnr20 += 1

    # o nome do jogador mais novo e com peso maior que 70 quilos.
    if maisNovo > idade and peso > 70:
        maisNovoNome = nome
        maisNovo = idade

    # a quantidade de jogadores do “santos” com idade maior que 20 ou com peso menor ou igual a 65 quilos
    if time == "santos":
        if idade > 20 or peso <= 65:
            sant20ou65 += 1

    # Após terminado o cadastro, perguntar se o usuário deseja cadastrar mais jogadores. Caso ele responda “sim” outro
    # cadastro deve ser efetuado.
    if input("Cadastrar outro jogador? ") != "sim":
        break

# Do contrário, deve ser informado:
if contCor80kg != 0:

    print("Os jogadores do corinthians com mais de 80kg tem uma idade média de {}.".format(cor80kg / contCor80kg))
else:
    print("Não foi cadastrado nenhum jogador do corinthians com mais de 80kg.")

print("{}% dos jogadores tem menos de 20 anos.".format((mnr20 / i) * 100))

if maisNovo != 127 and maisNovoNome != "":
    print("O jogador mais novo com mais de 70kg é {}, com {} anos.".format(maisNovoNome, maisNovo))
else:
    print("Não foi cadastrado nenhum jogador com mais de 70kg.")

print("{} jogadores do santos tem mais de 20 anos ou pesam menos ou igual a 65kg.".format(sant20ou65))
