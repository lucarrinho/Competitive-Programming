from heapq import heappush, heappop

def dijkstra(n, grafo, inicio):
    dist = [float('inf')]*n
    dist[inicio] = 0
    heap = [(0, inicio)]
    while heap:
        dist_atual, no = heappop(heap)
        if dist_atual > dist[no]:
            continue
        for vizinho, peso in grafo[no]:
            nova_dist = dist[no] + peso
            if dist[vizinho] > nova_dist:
                dist[vizinho] = nova_dist
                heappush(heap, (nova_dist, vizinho))
    return dist

n, m, k = map(int, input().split())
grafo = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    grafo[u-1].append((v-1, w))

dists = dijkstra(n, grafo, k-1)
maior = max(dists)
if maior == float('inf'):
    print(-1)
else:
    print(maior)