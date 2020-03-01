altura = float(input("Digite sua altura: "))
massa = float(input("Digite sua peso: "))

imc = massa / (altura * altura)

if imc < 18.5:
    print("Seu IMC é {} e você está abaixo do peso.".format(imc))
elif imc < 25:
    print("Seu IMC é {} e você está peso normal.".format(imc))
elif imc < 30:
    print("Seu IMC é {} e você está acima do peso.".format(imc))
else:
    print("Seu IMC é {} e você está obeso.".format(imc))
