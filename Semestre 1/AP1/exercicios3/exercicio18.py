a = 5000000
b = 7000000
i = 0

while a < b:
    i += 1
    a *= 1.03
    b *= 1.02
    print("No {}º ano, país A tem {} habitantes e país B tem {} habitantes.".format(i, a, b))
print("Demorou {} anos para país A ultrapassar país B.".format(i))
