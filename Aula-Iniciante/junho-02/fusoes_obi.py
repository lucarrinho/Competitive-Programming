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

n, k = map(int, input().split())
pais = [-1]*(n+1)
for _ in range(k):
    operacao, b1, b2 = input().split()
    b1, b2 = int(b1), int(b2)
    if operacao == "C":
        if find(b1, pais) == find(b2, pais):
            print("S")
        else:
            print("N")
    elif operacao == "F":
        union(b1, b2, pais)