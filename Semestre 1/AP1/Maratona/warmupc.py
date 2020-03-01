quant = int(input())
timeZonesInp = input()
somaTimeZones1 = 0
somaTimeZones2 = 0

timeZones = timeZonesInp.split()
timeZonesTemp = [int(x) for x in timeZones]
timeZonesDef = []

for i in timeZones:
    higherNmb = -13
    for element in timeZonesTemp:
        if element > higherNmb:
            higherNmb = element
    timeZonesDef += [higherNmb]
    timeZonesTemp.remove(higherNmb)

for i in range(0, quant, 2):
    soma1 = abs(timeZonesDef[i] - timeZonesDef[i-1])
    soma2 = 0
    i1temp = timeZonesDef[i]
    i2temp = timeZonesDef[i-1]
    while i1temp != i2temp:
        if i1temp == 12:
            i1temp = -11
            soma2 += 1
        else:
            i1temp += 1
            soma2 += 1

    if soma1 > soma2:
        somaTimeZones1 += soma2
    else:
        somaTimeZones1 += soma1

    soma1 = abs(timeZonesDef[i+1] - timeZonesDef[i])
    soma2 = 0
    i1temp = timeZonesDef[i+1]
    i2temp = timeZonesDef[i]
    while i1temp != i2temp:
        if i1temp == 12:
            i1temp = -11
            soma2 += 1
        else:
            i1temp += 1
            soma2 += 1

    if soma1 > soma2:
        somaTimeZones2 += soma2
    else:
        somaTimeZones2 += soma1

if somaTimeZones1 > somaTimeZones2:
    print(somaTimeZones2)
else:
    print(somaTimeZones1)
