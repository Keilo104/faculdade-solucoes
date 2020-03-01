a = 10000
b = 8000
i = 0

while a > b:
    a = a * 1.15
    b = b * 1.2
    i += 1

print("B supera A em {} meses.".format(i))