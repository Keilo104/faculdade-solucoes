import random

soma = 0
numimp = 0
mnrnmr = 50

while True:
    rand = random.randint(0, 50)
    soma += rand
    print(rand)
    if rand % 2 == 1:
        numimp += 1
    if rand < mnrnmr:
        mnrnmr = rand
    if rand == 32:
        break
print("A soma de todos os números é {}, foram gerados {} números ímpares e o menor número gerado foi {}.".format(soma, numimp, mnrnmr))
