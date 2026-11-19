def crivo(n):
    primos = [True]*(n+1)
    if n >= 0:
        primos[0] = False
    if n >= 1:
        primos[1] = False
    p = 3
    while p * p <= n:
        if primos[p]:
            multiplo = p*p
            while multiplo <= n:
                primos[multiplo] = False
                multiplo += p
        p += 1
    return primos

def fatoracao(n):
    primos = crivo(n)
    fatores = []
    p = 2
    while n > 1:
        while not primos[p]:
            p += 1
        if n % p == 0:
            fatores.append(p)
            n = n // p
        else:
            p += 1
            if p > n: break
    return fatores

n = int(input())

fatores = fatoracao(n)
print(fatores)