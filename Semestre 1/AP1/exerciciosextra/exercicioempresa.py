# As empresas A e B são fabricantes de carro e disputam o mercado no Brasil.
# Leia do usuário qual a quantidade de carros produzidos pela empresa A e sua respectiva taxa de crescimento anual.
a = int(input("Digite a quantidade de carros que a empresa A fabrica: "))
a50 = a
aUpassar = a
porA = 1 + float(input("Digite a taxa de crescimento anual da empresa A: "))
# Faça o mesmo para a empresa B.
b = int(input("Digite a quantidade de carros que a empresa B fabrica: "))
b50 = b
bUpassar = b
porB = 1 + float(input("Digite a taxa de crescimento anual da empresa B: "))
anos = 0
anosUpassar = 0

# Depois disso informe:
if a > b:
    print("Empresa A é líder de mercado.")  # qual delas é atualmente a líder de mercado
    if porB > porA:
        while aUpassar > bUpassar:  # caso a taxa de crescimento da empresa que é líder de mercado seja menor que a
            aUpassar *= porA        # taxa de crescimento da segunda colocada, informe em qual ano a segunda colocada
            bUpassar *= porB        # se tornará a líder.
            anosUpassar += 1
else:
    print("Empresa B é líder de mercado.")  # qual delas é atualmente a líder de mercado
    if porA > porB:
        while bUpassar > aUpassar:  # caso a taxa de crescimento da empresa que é líder de mercado seja menor que a
            aUpassar *= porA        # taxa de crescimento da segunda colocada, informe em qual ano a segunda colocada
            bUpassar *= porB        # se tornará a líder.
            anosUpassar += 1

while anos != 50:
    a50 *= porA
    b50 *= porB
    anos += 1

# informe qual será o cenário após 50 anos.
print("Em 50 anos, empresa A fabricará {} carros por ano e empresa B {} carros por ano.".format(a50, b50))

# caso a taxa de crescimento da empresa que é líder de mercado seja menor que a taxa de crescimento da segunda
# colocada, informe em qual ano a segunda colocada se tornará a líder.
if a > b:
    print("Demorará {} anos para B ultrapasssar A.".format(anosUpassar))
else:
    print("Demorará {} anos para A ultrapasssar B.".format(anosUpassar))
