import random

nums = 0
soma = 0
med = 0

while True:
    i = random.randint(0, 100)
    nums += 1
    soma += i
    print(i)
    if i == 88:
        med = soma / nums
        break

print("Foram gerados {} números, a soma deles é {} e a média é {}.".format(nums, soma, med))
