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

def tamanho(x, pais):
    raiz = find(x, pais)
    return -(pais[raiz])

def main():
    n = 6 # número de nós
    # cada nó é raiz de si mesmo
    pais = [-1]*n
    # unindo os nós
    union(0, 1, pais)
    union(1, 2, pais)
    union(3, 4, pais)
    # buscas
    print(find(0, pais)) #0
    print(find(2, pais)) #0
    print(find(3, pais)) #3
    print(find(4, pais)) #3
    print(find(5, pais)) #5
    #tamanho
    print(tamanho(0, pais)) #3
    print(tamanho(3, pais)) #2
    print(tamanho(5, pais)) #1

#main()