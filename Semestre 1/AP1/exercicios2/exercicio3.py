cidade = input("Digite o local onde o lote está localizado: ")
lado = int(input("Digite o lado do lote: "))
comprimento = int(input("Digite o comprimento do lote: "))

area = lado * comprimento

if cidade == "Curitiba":
    valor = area * 450
    print("O lote vale {}".format(valor))
else:
    if cidade == "São Paulo":
        valor = area * 500
        print("O lote vale {}".format(valor))
