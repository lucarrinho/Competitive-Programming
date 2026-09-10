def find(x, pais):
    if pais[x] < 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]

def union(a, b, pais):
    raiz_a = find(a, pais)
    raiz_b = find(b, pais)
    
    if raiz_a == raiz_b:
        return False
    
    if raiz_b < raiz_a:
        raiz_a, raiz_b = raiz_b, raiz_a
    
    pais[raiz_a] += pais[raiz_b]
    pais[raiz_b] = raiz_a
    return True

def maior(pais):
    raiz = min(pais)
    return -raiz

n, m = map(int, input().split())
pais = [-1]*n
for _ in range(m):
    a, b = map(int, input().split())
    union(a-1, b-1, pais)

print(maior(pais))