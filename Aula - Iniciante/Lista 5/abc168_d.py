from collections import deque

def main():
    n, m = map(int, input().split())
    caverna = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        caverna[a-1].append(b-1)
        caverna[b-1].append(a-1)

    placas = {}
    visitados = set([0])
    fila = deque([0])
    while fila:
        nodo_atual = fila.popleft()
        for filho in caverna[nodo_atual]:
            if filho not in visitados:
                fila.append(filho)
                placas[filho] = nodo_atual+1
                visitados.add(filho)

    if len(visitados) < n:
        print("No")
    else:
        print("Yes")
        for i in range(1, n):
            print(placas[i])

main()