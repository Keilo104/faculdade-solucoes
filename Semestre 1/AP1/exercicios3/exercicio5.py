a = 0
b = 1
i = 0

while a < 500:
    i += 1
    print("{}º número: {}".format(i, a))
    a, b = b, a + b
print("O primeiro número maior que 500 é {}.".format(a))
