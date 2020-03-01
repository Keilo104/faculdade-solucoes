fact = int(input("Digite um número para ser fatorializado: "))

i = 0
res = 1

while i < fact:
    res = res * (fact - i)
    i += 1
print(res)