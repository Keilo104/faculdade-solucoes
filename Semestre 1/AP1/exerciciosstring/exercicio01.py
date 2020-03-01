# - verifique se a primeira string é um CPF no formato xxx.xxx.xxx-xx.
# - verifique se a segunda string é uma data válida no formato DD/MM/AAAA. O Ano deve estar entre 1900 e 2020.
# - verifique se a terceira string é um palíndromo. Um palíndromo é uma sequência de caracteres na qual a leitura é
# idêntica se feita da direita para esquerda ou da esquerda para a direita. Exemplo: OVO. Considerar também frases
# complexas nas quais os espaços e pontuação devem ser ignorados. Ex: SUBI NO ONIBUS.
import string

# Faça um programa em python que receba três strings
str1 = input("Digite a primeira string: ")
str2 = input("Digite a segunda string: ")
str3 = input("Digite a terceira string: ")
str1ok = True
str3ok = True

# - verifique se a primeira string é um CPF no formato xxx.xxx.xxx-xx.
if len(str1) == 14:  # checa se tem a quantidade de caracteres de um cpf
    if str1[3] == "." and str1[7] == "." and str1[11] == "-":  # verifica se os caracteres 4 e 8 são pontos e 12 é hífen
        for i in range(0, len(str1)):
            if i == 3 or i == 7 or i == 11:  # caso os caracteres sejam 4, 8 e 12, eles não precisam ser verificados
                continue                     # novamente
            if i == 13:                                         # caso especial para o caractere 14
                if str1[i] in string.digits or str1[i] == "X":  # checa se ele é um número ou "X"
                    continue
                else:
                    str1ok = False
                    break
            if str1[i] not in string.digits:  # verifica se todos os outros caracteres são números
                str1ok = False
                break
    else:
        str1ok = False
else:
    str1ok = False

# printa a resposta
if str1ok:
    print("{} é um cpf válido.".format(str1))
else:
    print("Não foi digitado um cpf válido.")

if len(str2) == 10:  # checa se a quantidade de caracteres condiz com uma data
    if str2[2] and str2[5] == "/":  # checa se os caracteres 3 e 6 são barras
        dia = int(str2[0:2])    # cria variáveis para dia,
        mes = int(str2[3:5])    # mês e
        ano = int(str2[6:11])   # ano
        if 0 < dia < 32 and 0 < mes < 12 and 1900 < ano < 2020:  # checa se a data é válida
            print("A data digitada existe.")  # printa a resposta
        else:
            print("A data digitada não é válida.")
    else:
        print("A data digitada não é válida.")
else:
    print("A data digitada não é válida.")

str3nova = str3.replace(" ", "").lower()  # cria uma string nova, ela é str3 sem espaços e tudo em minúsculo

for i in string.punctuation:  # remove todas as pontuaçãoes da str3nova
    str3nova = str3nova.replace(i, "")

for i in range(0, len(str3nova) // 2):  # o loop só roda o suficiente para metade da frase/palavra
    if str3nova[i] != str3nova[(-i) - 1]:  # checa se o índice da str3nova é igual ao índice oposto da string
        str3ok = False
        break

# printa a resposta da verificação
if str3ok:
    print("{} é um palíndromo válido.".format(str3))
else:
    print("Não foi digitado um palíndromo válido.")
