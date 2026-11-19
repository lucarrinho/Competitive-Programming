from sys import setrecursionlimit
setrecursionlimit(200000)

def dfs(no, mapa, caminho_percorrido):
    i, j = no
    mapa[i][j] = "."
    caminho_percorrido.append((i+1, j+1))
    direcoes = [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]
    for x, y in direcoes:
        if (0 <= x < l) and (0 <= y < c):
            if mapa[x][y] == "H":
                dfs((x, y), mapa, caminho_percorrido)
    

l, c = map(int, input().split())
mapa = []
for i in range(l):
    linha = []
    ent = input()
    for j in range(len(ent)):
        linha.append(ent[j])
        if ent[j] == "o":
            inicio = (i, j)
    mapa.append(linha)

caminho_percorrido = []
dfs(inicio, mapa, caminho_percorrido)
final = caminho_percorrido[-1]
print(final[0], final[1])