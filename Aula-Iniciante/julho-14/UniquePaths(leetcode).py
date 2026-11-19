m, n = map(int, input().split())
dp = [[-1]*n]*m
dp[0] = [1]*n
for i in range(1, m):
    dp[i][0] = 1
    for j in range(1, n):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
print(dp[m-1][n-1])