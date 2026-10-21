import sys
input = sys.stdin.readline

n, w = map(int, input().split())
item = []
for _ in range(n):
    wi, vi = map(int, input().split())
    item.append((wi, vi))

dp = []
for i in range(n+1):
    linha = []
    for j in range(w+1):
        linha.append(0)
    dp.append(linha)

for i in range(1, n+1):
    peso, valor = item[i-1]
    for j in range(w+1):
        if peso <= j:
            print(i, j, peso, valor)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-peso]+vi)
            print("dp em tempo real",dp[i][j])

print(dp[n][w])