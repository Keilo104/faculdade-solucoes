import nltk
nltk.download('rslp')

textoOrigem = input("Digite o nome do arquivo do texto a ser lido: ")
resumoOrigem = input("Digite o nome do arquivo do resumo a ser lido: ")

arqOrigem = open(textoOrigem, "r")
listaOri = []
stemmer = nltk.stem.RSLPStemmer()

for linha in arqOrigem:
    linha.split()
    for x in linha:
        stemmer.stem(x)
        listaOri += [x]

print(listaOri)