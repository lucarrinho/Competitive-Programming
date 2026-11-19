from heapq import heappush, heappop

def dijkstra(grafo, inicio):
    n = len(grafo)
    dist = [float('inf')]*n
    dist[inicio] = 0
    hea = [(0, inicio)]
    while hea:
        distancia_atual, no = heappop(hea)
        if distancia_atual > dist[no]:
            continue
        for vizinho, peso in grafo[no]:
            nova_dist = dist[no] + peso
            if dist[vizinho] > nova_dist:
                dist[vizinho] = nova_dist
                heappush(hea, (nova_dist, vizinho))
    return dist

n, m = map(int, input().split())
grafo = [[] for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    grafo[a-1].append((b-1, c))

print(" ".join(map(str, dijkstra(grafo, 0))))