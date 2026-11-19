def find(x, pais):
    if pais[x] < 0:
        return x
    pais[x] = find(pais[x], pais)
    return pais[x]

def union(a, b, pais):
    raiz_a, raiz_b = find(a, pais), find(b, pais)
    if raiz_a == raiz_b:
        return False
    if pais[raiz_b] < pais[raiz_a]:
        raiz_a, raiz_b = raiz_b, raiz_a
    pais[raiz_a] += pais[raiz_b]
    pais[raiz_b] = raiz_a
    return True

def kruskal(arestas, malha, n):
    arestas.sort()
    
    custoTotal = 0
    arvore = []
    for custo, u, v in arestas:
        if union(u, v, malha):
            custoTotal += custo
            arvore.append((u, v, custo))
        if len(arvore) == n-1:
            break
    
    return custoTotal

n, f, r = map(int, input().split())

malha = [-1]*(n+1)
ferrovias = []
for _ in range(f):
    a, b, c = map(int, input().split())
    ferrovias.append((c, a, b))
custo = kruskal(ferrovias, malha, n)

rodovias = []
for _ in range(r):
    i, j, k = map(int, input().split())
    rodovias.append((k, i, j))
custo += kruskal(rodovias, malha, n)

print(custo)