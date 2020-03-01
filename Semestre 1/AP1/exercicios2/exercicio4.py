notaProva = float(input("Digite a nota de prova do aluno: "))
notaTrab = float(input("Digite a nota de trabalho do aluno: "))
freq = float(input("Digite a frequência do aluno: "))

notaTot = (0.7 * notaProva) + (0.3 * notaTrab)
print(notaTot)

if freq >= 75:
    if notaTot >= 6:
        print("Aluno foi aprovado")
    else:
        if notaTot >= 4:
            print("Aluno ficou de recuperação")
        else:
            print("Aluno foi reprovado")
else:
    print("Aluno foi reprovado")
