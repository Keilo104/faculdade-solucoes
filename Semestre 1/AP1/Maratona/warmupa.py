angle = int(input())
dicionarioAngulos = []

for hora in range(0, 13):
    for minuto in range(0, 61):
        horaAng = (hora + (minuto // 12)) * 6
        minutoAng = minuto * 6
        ang1 = abs(horaAng - minutoAng)
        ang2 = 360 - ang1
        if ang1 > ang2:
            dicionarioAngulos.append(ang2)
        else:
            dicionarioAngulos.append(ang1)

if angle in dicionarioAngulos:
    print("Y")
else:
    print("N")
