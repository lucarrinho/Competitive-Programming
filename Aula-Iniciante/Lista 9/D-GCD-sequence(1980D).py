from math import gcd
from sys import stdin

def check(lista, n, indexProblema=-1):
    if indexProblema != -1:
        lista.pop(indexProblema)
    mdc = [gcd(lista[0], lista[1])]
    for i in range(1, n-1):
        x = gcd(lista[i], lista[i+1])
        if x < mdc[-1]:
            return i
        else:
            mdc.append(x)
    return -1

for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    lista = list(map(int, stdin.readline().split()))
    
    index = check(lista, n)
    passou = True
    if index != -1:
        passou = False
        if check(lista[:], n-1, index) == -1:
           passou = True
        elif check(lista[:], n-1, index+1) == -1:
            passou = True
        elif check(lista[:], n-1, index-1) == -1:
            passou = True
    if passou:
        print("YES")
    else:
        print("NO")