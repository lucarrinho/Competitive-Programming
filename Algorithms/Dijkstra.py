from heapq import heappush, heappop # min-heap

def dijkstra(grafo, inicio): #inicio: nó inicial
    n = len(grafo) #numero de nós
    # distância inicial, infinita para todos
    dist = [float('inf')] * n
    dist[inicio] = 0 # a dist. de (inicio,inicio) = 0
    # heap com pares: (distância para source, vértice)
    heap = [(0, inicio)]
    while heap: # enquanto tivermos nós
        # pega a menor distância para source (método guloso)
        distancia_atual, no = heappop(heap)
        # se a distância for maior do que temos, ignora
        if distancia_atual > dist[no]: # não tem decrease key
            continue # ignoramos na heap chave maior para nó
        # percorre os vizinhos do nó
        for vizinho, peso in grafo[no]:
            nova_dist = dist[no] + peso
            if nova_dist < dist[vizinho]: # se tem caminho melhor
                dist[vizinho] = nova_dist # relaxamento
                # add nova priorid. menor para vizinho na min-heap
                heappush(heap, (nova_dist, vizinho))
    return dist

grafo = [
    [(1, 4), (2, 1)],
    [(3, 1)],
    [(1, 2),(3, 5)],
    []
]
# saída: [0, 3, 1, 4]
print(dijkstra(grafo, 0))
