odInicial = int(input("Digite a marcação do odômetro no início do dia: "))
odFinal = int(input("Digite a marcação do odômetro no final do dia: "))
combGasto = float(input("Digite a quantidade de litros de combustível gastos hoje: "))
lucroB = float(input("Digite o lucro bruto recebido dos passageiros hoje: "))

km = odFinal - odInicial
kml = combGasto / km
lucroL = lucroB - (combGasto * 2.50)

print("Você gasta em média {} litros de combustível por kilômetro".format(kml))
print("Você teve um lucro líquido de {} reais hoje".format(lucroL))
if lucroL < 100:
    print("Atenção! Você fez menos que 100 reais hoje, você deve melhorar seu desempenho.")