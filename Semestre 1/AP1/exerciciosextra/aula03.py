class Aluno:
    def __init__(self):
        self.nome = ""
        self.idade = 0


andre = Aluno()
andre.nome = "Andre Ditomaso"
andre.idade = 39

print("nome: {}".format(andre.nome))
print("idade: {}".format(andre.idade))

while True:

    a = Aluno()
    a.nome = input("Digite o nome do aluno ")
    a.idade = int(input("Digite a idade do aluno: "))
    choice = input("Digite a opção: ")

    if choice == 0:
        break

print("nome: {}".format(a.nome))
print("idade: {}".format(a.idade))
