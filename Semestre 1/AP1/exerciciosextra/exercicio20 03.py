i, luxoBarato, precoLuxo, qtdLuxo, qtdComum, maisCaro, entre100e200 = 0, 0, 0, 0, 0, 0, 0
preco = 1
comumMaisBarato = 10000000
maisCaroNome, comumMaisBaratoNome = "", ""

# Faça um programa para informatizar o cadastro de produtos em uma loja.
while True:
    # Cada produto deve ser armazenado com as seguintes informações: nome, preço, quantidade e categoria (“L” para luxo
    # e “C” para comum).
    nome = input("Digite o nome do {}º item: ".format(i + 1))
    preco = float(input("Digite o preço do {}º item: ".format(i + 1)))
    qntd = int(input("Digite a quantidade do {}º item: ".format(i + 1)))
    ctgr = input("Digite a categoria do {}º item(\"C\" ou \"L\"): ".format(i + 1))

    # Você deve cadastrar produtos até o preço 0 ser cadastrado.
    if preco == 0:
        break

    i += 1

    if ctgr == "L":
        # - o preço médios dos produtos de luxo
        precoLuxo += preco
        qtdLuxo += 1
        # - a quantidade de produtos de luxo com preço menos de R$ 2000,00
        if preco < 2000:
            luxoBarato += 1
    # - o nome do produto comum mais barato
    else:
        qtdComum += 1
        if preco < comumMaisBarato:
            comumMaisBarato = preco
            comumMaisBaratoNome = nome

    # - o nome do produto mais caro com quantidade menos que 50.
    if qntd < 50 and preco > maisCaro:
        maisCaro = preco
        maisCaroNome = nome

    # - o percentual de produtos que custam entre R$ 100,0 e R$ 200,00.
    if 100 < preco < 200:
        entre100e200 += 1

# Depois de cadastrados os animais informe:
if i != 0:
    if qtdLuxo != 0:

        # - o preço médios dos produtos de luxo
        luxoMedio = precoLuxo / qtdLuxo

        print("Foram cadastrados {} produtos de luxo com preço menor de R$2000,00.".format(luxoBarato))
        print("O preço médio dos produtos de luxo é R${}.".format(luxoMedio))
    else:
        print("Não foram digitados produtos de luxo")

    # - o percentual de produtos que custam entre R$ 100,0 e R$ 200,00.
    porc100e200 = (entre100e200 / i) * 100

    print("O produto mais caro e com quantidade menor que 50 é {}.".format(maisCaroNome))
    print("{}% dos produtos custam entre R$100,00 e R$200,00.".format(porc100e200))

    if qtdComum != 0:
        print("O produto", comumMaisBaratoNome, "é o produto comum mais barato.")
    else:
        print("Não foram digitados produtos comuns.")
else:
    print("Não foram digitados produtos.")
