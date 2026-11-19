coins = list(map(int, input().split()))
amount = int(input())
dp = [float('inf')]*(amount+1)
dp[0] = 0

for i in range(1, amount+1):
    for moeda in coins:
        if i - moeda >= 0:
            dp[i] = min(dp[i], 1 + dp[i - moeda])

if dp[amount] == float('inf'):
    print(-1)
else:
    print(dp[amount])