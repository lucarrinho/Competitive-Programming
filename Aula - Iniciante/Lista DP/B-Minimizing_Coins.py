from sys import stdin
input = stdin.readline

n, x = map(int, input().split())
coins = list(map(int, input().split()))
coins.sort()

INF = 10**9
dp = [INF]*(x+1)
dp[0] = 0

for i in range(1, x+1):
    for moeda in coins:
        if moeda > i:
            break
        dp[i] = min(dp[i], 1 + dp[i - moeda])

if dp[x] == INF:
    print(-1)
else:
    print(dp[x])