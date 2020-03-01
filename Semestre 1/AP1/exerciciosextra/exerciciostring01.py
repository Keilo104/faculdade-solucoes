# Faça um programa em python que receba três strings
# - verifique se a segunda string é uma data válida no formato DD/MM/AAAA. O Ano deve estar entre 1900 e 2020.
# - verifique se a terceira string é um palíndromo. Um palíndromo é uma sequência de caracteres na qual a leitura é
# idêntica se feita da direita para esquerda ou da esquerda para a direita. Exemplo: OVO. Considerar também frases
# complexas nas quais os espaços e pontuação devem ser ignorados. Ex: SUBI NO ONIBUS.

import string

str1 = input("Digite a primeira string: ")
# str2 = input("Digite a segunda string: ")
# str3 = input("Digite a terceira string: ")
str1ok = True
str2ok = True
str3ok = True
i = 0

# - verifique se a primeira string é um CPF no formato xxx.xxx.xxx-xx.
for letra in str1:
    if i == [0, 1, 2, 4, 5, 6, 8, 9, 10, 12] and letra not in [0]:
        str1ok = False
    if i == 13 and (letra not in [0] or letra != "X"):
        str1ok = False
    if i == [3, 7] and letra != ".":
        str1ok = False
    if i == 11 and letra != "-":
        str1ok = False
    i += 1
if str1ok == True:
    print("A string digitada é um cpf.")
else:
    print("A string digitada não é um cpf.")