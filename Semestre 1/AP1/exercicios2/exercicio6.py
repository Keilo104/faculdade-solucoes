comp = float(input("Digite o comprimento da cozinha: "))
larg = float(input("Digite a largura da cozinha: "))
alt = float(input("Digite a altura da cozinha: "))

parede1 = comp * alt
parede2 = larg * alt
azulejo = parede1 + parede2

print("Sua cozinha irá precisar de {} azujelos".format(azulejo))
