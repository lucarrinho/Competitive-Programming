import sys
input = sys.stdin.readline

def dsf(grafo, nodo, n):
    if nodo == n:
        return (True, 0)
    for prox in grafo[nodo]:
        x, w = prox
        res = dsf(grafo, x, n)
        if res[0] == True:
            return (True, res[1] | w)
    return (False, 0)

n, m = map(int, input().split())
grafo = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    grafo[u-1].append((v-1, w))

result = dsf(grafo, 1, n)[1]
print(result)