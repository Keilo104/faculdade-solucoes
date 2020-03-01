import random

par = 0
i = 0

while True:
    i = random.randint(0, 100)
    print(i)
    if i % 2 == 0:
        par += 1
    if i == 50:
        break

print("Foram gerados {} números pares.".format(par))
