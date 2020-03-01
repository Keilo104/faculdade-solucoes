num = int(input("Digite um número: "))

mod = num % 10

if mod == 0:
    print("O número {} é divisível por 10, 5 e 2".format(num))
else:
    mod = num % 2
    if mod == 0:
        print("O número {} é divisível por 2".format(num))
    else:
        mod = num % 5
        if mod == 0:
            print("O número {} é divisível por 5".format(num))
        else:
            print("O número {} não é divisível por 2, 5 ou 10".format(num))
