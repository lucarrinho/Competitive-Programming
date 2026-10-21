import math

n = int(input())
lista = list(map(int, input().split()))

g = lista[0]
for i in range(1, n):
    g = math.gcd(g, lista[i])

divisores = 0
i = 1
while i*i <= g:
    if g % i == 0:
        outro = g // i
        if outro == i:
            divisores += 1
        else:
            divisores += 2
    i += 1

print(divisores)