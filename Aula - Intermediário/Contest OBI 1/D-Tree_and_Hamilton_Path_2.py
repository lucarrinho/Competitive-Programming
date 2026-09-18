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
    
    if pais[raiz_b] < pais[raiz_a]:
        raiz_a, raiz_b = raiz_b, raiz_a
    
    pais[raiz_a] += pais[raiz_b]
    pais[raiz_b] = raiz_a
    return True

def kruskal(n, arestas, pais):
    arestas.sort()
    custo_total = 0
    arvore_minima = []
    for peso, u, v in arestas:
        if union(u, v, pais):
            custo_total += peso
            arvore_minima.append((u, v, peso))
        if len(arvore_minima) == n-1:
            break

    if len(arvore_minima) != n-1:
        return None
    return custo_total

n = int(input())
pais = [-1]*(n+1)
arestas = []
for _ in range(n-1):
    a, b, c = map(int, input().split())
    arestas.append((c, a-1, b-1))

v = kruskal(n, arestas, pais)
print(v)