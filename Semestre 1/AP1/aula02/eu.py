nome = input("Digite o nome do aluno: ")
nota = float(input("Digite a nota de {}: ".format(nome)))
freq = float(input("Digite a frequência de {}: ".format(nome)))

if freq >= 75:
    if nota >= 6:
        print("{} passou!".format(nome))
    else:
        if nota >= 4:
            print("{} ficou no IFA.".format(nome))
        else:
            print("{} reprovou.".format(nome))
else:
    print("{} reprovou.".format(nome))
