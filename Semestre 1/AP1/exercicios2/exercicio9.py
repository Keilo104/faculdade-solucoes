num = int(input("Digite um número: "))

mod = num % 2

if mod == 1:
    print("O número {} é ímpar".format(num))
else:
    print("O número {} é par".format(num))
