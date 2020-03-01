import random

mnr10 = 0
i = 0

while True:
    i = random.randint(0, 100)
    print(i)
    if i < 10:
        mnr10 += 1
    if i == 45:
        break

print("Foram gerados {} números menores que 10.".format(mnr10))
