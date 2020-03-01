# Faça um programa para informatizar o cadastro dos pacientes em um hospital.
i = 0
cadastro = "sim"
maisVelho = 0
maisVelhoNome = ""
pesoMedio = 0
contSexoFem = 0
pacienteMou45 = 0
idoso = 0

while cadastro == "sim":
    cadastro = ""
    i += 1
    nome = input("Digite o nome do {}º paciente: ".format(i))         # Você deve cadastrar os pacientes com as
    idade = int(input("Digite a idade do {}º paciente: ".format(i)))  # seguintes informações: nome, idade, sexo
    sexo = input("Digite o sexo do {}º paciente: ".format(i))         # (M ou F) e peso.
    peso = float(input("Digite o peso do {}º paciente: ".format(i)))

    if idade > maisVelho and peso > 50:  # o nome do paciente mais velho e com peso maior que 50 quilos.
        maisVelho = idade
        maisVelhoNome = nome

    if sexo == "F" and idade > 30:       # peso médio dos pacientes do sexo feminino com mais de 30 anos.
        pesoMedio += peso
        contSexoFem += 1

    if sexo == "M" or idade < 45:        # a quantidade de pacientes do sexo masculino ou com idade menor que 45 anos.
        pacienteMou45 += 1

    if idade > 59:                       # o percentual de pacientes (masculino ou feminino) que são idosos (mais de
        idoso += 1                       # 59 anos).

    while cadastro != "sim" and cadastro != "não":                    # Após terminado o cadastro, perguntar se o usuário deseja cadastrar mais
        cadastro = input("Deseja continuar cadastrando? (sim/não) ")  # alunos. Caso ele responda “sim” outro cadastro deve ser efetuado.

idosoPerc = (idoso / i) * 100

# Do contrário, deve ser informado:

if maisVelho != 0:
    print("O paciente mais velho com peso maior de 50 quilso se chama {}, com {} anos.".format(maisVelhoNome, maisVelho))
else:
    print("Não foram cadastrados pessoas com mais de 50 quilos")

if contSexoFem != 0:
    pesoMedio = pesoMedio / contSexoFem
    print("O peso médio das pacientes do sexo feminino com mais de 30 anos é {}.".format(pesoMedio))
else:
    print("Não foram cadastradas pacientes de sexo feminino com mais de 30 anos.")

if pacienteMou45 != 0:
    print("Foram cadastrados {} pacientes de sexo masculino ou menor de 45 anos.".format(pacienteMou45))
else:
    print("Não foram cadastrados pacientes de sexo masculino ou menor de 45 anos.")

print("{}% dos pacientes cadastrados eram idosos(maiores de 59 anos.)".format(idosoPerc))
