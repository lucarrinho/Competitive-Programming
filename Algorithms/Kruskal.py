from Dsu import union

def kruskal(n, arestas, pais):
    arestas.sort() # ordena as arestas pelo peso (n*log n)
    # guarda a soma dos pesos das arestas escolhidas
    custo_total = 0
    arvore_minima = [] #arestas da árvore geradora mínima
    # percorre as arestas da menor para a maior
    for peso, u, v in arestas:
        # tenta unir os conjuntos de u e v
        if union(u, v, pais): # se não tiver ciclo
            custo_total += peso # atualiza custo
            # adiciona a aresta à árvore geradora mínima
            arvore_minima.append((u, v, peso))
            # uma árvore com n vertices tem n-1 arestas
            # então podemos parar aqui
        if len(arvore_minima) == n-1: # otimização
            break # concluimos

    # se não conseguirmos escolher n-1 arestas,
    if len(arvore_minima) != n-1:
        return None
    # retorna a árvore escolhida e o custo total
    return arvore_minima, custo_total

def main():
    n = 4 # num de nós
    pais = [-1]*(n+1)
    arestas = [ #grafo
        (1, 1, 2),
        (4, 1, 3),
        (2, 2, 3),
        (3, 2, 4),
        (5, 3, 4)
        ]
    # gera a arvore
    result = kruskal(n, arestas, pais)
    if result is None:
        print("Não tem")
    else:
        arvore, custo = result
        print("Arestas: ", arvore)
        print("Custo: ", custo)

main()