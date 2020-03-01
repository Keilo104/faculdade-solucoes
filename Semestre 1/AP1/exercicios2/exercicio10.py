num = int(input("Digite um número: "))

mod = num % 3

if mod == 0:
    print("O número {} é divisível por 3".format(num))
else:
    print("O número {} não é divisível por 3".format(num))
