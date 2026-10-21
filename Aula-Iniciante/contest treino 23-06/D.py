import sys

def find(x, pais):
    if pais[x] < 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]
def union(a, b, pais, maior):
    raiz_a, raiz_b = find(a, pais), find(b, pais)
    if raiz_a == raiz_b:
        return maior
    if pais[raiz_b] < pais[raiz_a]:
        raiz_a, raiz_b = raiz_b, raiz_a
    pais[raiz_a] += pais[raiz_b]
    pais[raiz_b] = raiz_a
    return max(maior, tamanho(raiz_a, pais))
def tamanho(x, pais):
    raiz_x = find(x, pais)
    return -pais[raiz_x]

n, m = map(int, sys.stdin.readline().split())
pais = [-1]*n
maior = 1
for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    maior = union(i-1, j-1, pais, maior)
print(maior)