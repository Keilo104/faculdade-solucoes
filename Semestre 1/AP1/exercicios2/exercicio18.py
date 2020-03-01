idade = int(input("Digite a idade da pessoa: "))
sexo = input("Digite o sexo da pessoa: ")
salario = float(input("Digite o salário da pessoa: "))

if sexo == "Masculino" and idade > 18:
    print("A pessoa é masculina com mais de 18 anos.")
elif sexo == "Feminino" and salario > 50000 and idade > 40:
    print("A pessoa é feminina, com salário maior que R$50.000,00 e maior de 40 anos.")
elif idade > 20 and idade < 30:
    print("A pessoa é masculina ou feminina e tem idade entre 20 e 30 anos.")
else:
    print("A pessoa não se encaixa em nenhuma possibilidade.")
