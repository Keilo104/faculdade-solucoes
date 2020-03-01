#receber dados de prova, trabalho e frequencia
notaprova = float(input("Digite a nota da prova"))
notatrabalho = float(input("Digite a nota do trabalho"))
frequencia = float(input("Digite a frequencia do aluno"))

#calcular media do aluno
media = notaprova*0.7 + notatrabalho*0.3
print("A media do aluno é ".format(media))

#verificar qual categoria o aluno está
#nota >=0 e frequencia > 75%
if media >=6 and frequencia >=75:
    print("Parabéns, vc foi aprovado!")
else:
    if media >=4 and media < 6 and frequencia >=75:
        print("Voce está de Recuperaçao Final")
    else:
        if media <=4 or frequencia < 75:
            print("Infelizmente voce está reprovado!")
