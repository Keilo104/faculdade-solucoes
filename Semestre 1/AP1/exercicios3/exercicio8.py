n = int(input("Digite o número de alunos na sala: "))

i = 0
res = 0

while i != n:
    i += 1
    aluno = int(input("Digite a idade do {}º aluno: ".format(i)))
    res = res + aluno

res = res / n

if res < 26:
    print("A média de idade na sala é {} e a sala é jovem.".format(res))
elif res < 61:
    print("A média de idade na sala é {} e a sala é adulta.".format(res))
else:
    print("A média de idade na sala é {} e a sala é idosa.".format(res))