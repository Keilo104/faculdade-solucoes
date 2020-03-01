num = int(input("Digite a quantidade de números a ser digitado: "))

marnmr = 0
i = 0

while num != i:
    i += 1
    inp = int(input("Digite o {}º número: ".format(i)))
    if inp > marnmr:
        marnmr = inp
print("O maior número digitado foi {}.".format(marnmr))
