idade = int(input("Digite a idade da pessoa: "))

if idade < 16:
    print("A pessoa não é eleitora.")
elif idade < 18 or idade >= 65:
    print("A pessoa é eleitora facultativa.")
else:
    print("A pessoa é eleitora obrigatória.")
