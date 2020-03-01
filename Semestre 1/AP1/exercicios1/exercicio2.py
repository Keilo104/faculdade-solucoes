salario = int(input("Digite seu salário: "))

salarioAnual = salario * 12
tempoMilhao = 1000000 / salarioAnual
impostoMes = salario / 4

print("Seu salário anual é: {}".format(salarioAnual))
print("Para acumular um milhão de reais, demoraria {} anos".format(tempoMilhao))
print("Você deve pagar {} em impostos por mês".format(impostoMes))