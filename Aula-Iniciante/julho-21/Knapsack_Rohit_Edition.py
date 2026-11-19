n, w = map(int, input().split())
peso = [0]*(n+1)
valor = [0]*(n+1)
for i in range(1, n+1):
    peso[i], valor[i] = map(int, input().split())