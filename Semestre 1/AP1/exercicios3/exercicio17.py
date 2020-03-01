pessoas = int(input("Digite a quantidade de pessoasa serem cadastradas: "))

somaIdade = 0
peso90 = 0
idade10e30 = 0
maior190 = 0
i = 0

for i in range(0, pessoas):
    idade = int(input("Digite a idade da {}ª pessoa: ".format(i)))
    peso = float(input("Digite a peso da {}ª pessoa: ".format(i)))
    altura = float(input("Digite a altura da {}ª pessoa: ".format(i)))

    somaIdade += idade

    if peso > 90 and altura < 1.50:
        peso90 += 1

    if altura > 1.90:
        maior190 += 1
        if 10 < idade < 30:
            idade10e30 += 1

mediaIdade = somaIdade / pessoas
porcentagem190 = (idade10e30 / maior190) * 100

print("A média de idade das pessoas é {}.".format(mediaIdade))
print("Foram cadastradas {} pessoas com peso superior a 90 quilos e altura inferior a 1,50m.".format(peso90))
print("{}% das pessoas cadastradas que medem mais de 1,90m tem entre 10 e 30 anos .".format(porcentagem190))
