idade = int(input("Digite a idade da pessoa: "))

if idade < 18:
    print("A pessoa é menor de idade.")
elif idade < 65:
    print("A pessoa é maior de idade.")
else:
    print("A pessoa é idosa.")
