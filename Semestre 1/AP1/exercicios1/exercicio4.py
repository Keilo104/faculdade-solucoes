massa = float(input("Digite seu peso: "))
altura = float(input("Digite sua altura: "))

imc = massa / (altura * altura)

if imc < 16:
    print("Seu imc é {} e você é classificado como \"Magreza grave\"".format(imc))
elif imc < 17:
    print("Seu imc é {} e você é classificado como \"Magreza moderada\"".format(imc))
elif imc < 18.5:
    print("Seu imc é {} e você é classificado como \"Magreza leve\"".format(imc))
elif imc < 25:
    print("Seu imc é {} e você é classificado como \"Saudável\"".format(imc))
elif imc < 30:
    print("Seu imc é {} e você é classificado como \"Sobrepeso\"".format(imc))
elif imc < 35:
    print("Seu imc é {} e você é classificado como \"Obesidade Grau I\"".format(imc))
elif imc < 40:
    print("Seu imc é {} e você é classificado como \"Obesidade Grau II (severa)\"".format(imc))
else:
    print("Seu imc é {} e você é classificado como \"Obesidade Grau III (mórbida)\"".format(imc))