import math

cat1 = input("Digite o primeiro cateto: ")
cat2 = input("Digite o segundo cateto: ")
hip = input("Digite a hipotenusa: ")

if cat1 == "x":
    cat1 = math.sqrt((int(hip) ** 2) - (int(cat2) ** 2))
    print("O primeiro cateto é {}.".format(cat1))
elif cat2 == "x":
    cat2 = math.sqrt((int(hip) ** 2) - (int(cat1) ** 2))
    print("O segundo cateto é {}.".format(cat2))
elif hip == "x":
    hip = math.sqrt((int(cat1) ** 2) + (int(cat2) ** 2))
    print("A hipotenusa é {}.".format(hip))
else:
    print("tu precisa dar um x, otário")