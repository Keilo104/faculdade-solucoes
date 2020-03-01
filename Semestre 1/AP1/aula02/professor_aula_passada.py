#criando uma variável chamada "nome"
#utilizar a funcao input para receber do usuário um valor que será
#atribuido para a variavel nome
nome = input("Digite seu nome: ")

#escrevendo na tela o que foi digitado pelo usuário
print("Bom dia " + nome + " !!!")
print(nome + " seja bem vindo!!")

#criando uma variável para o salario
salario = float(input("Digite seu salário: "))

print ("Seu salario é {}".format(salario))
print("Seu salario é " + str(salario))

salarioAno = salario*13

print("Seu salário no ano é : " + str(salarioAno))

if salarioAno > 20000:
    print("Seu salário é maior que 20 mil no ano")
    print("Parabéns")
else:
    if salarioAno > 15000:
        print("Seu salário é maior que 15 mil no ano")
    else:
        print("Seu salário é menor que 15 mil no ano")
