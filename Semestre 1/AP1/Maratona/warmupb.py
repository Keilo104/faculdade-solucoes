nro = int(input())
br1 = input()
br2 = input()
input()
dicionario = [".***", "*...", "*.*.", "**..", "**.*", "*..*", "***.", "****", "*.**", ".**."]
resultado = ""

for i in range(0, (nro * 3), 3):
    resultadoTemp = br1[i:i+2] + br2[i:i+2]
    resultado += str(dicionario.index(resultadoTemp))
print(resultado)
