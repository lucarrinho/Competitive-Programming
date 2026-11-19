import sys
input = sys.stdin.readline

n = int(input())
dp = [-1]*(n+1)
dp[0] = 0
for i in range(1, n+1):
    if i < 10:
        dp[i] = 1
    else:
        aux = sorted([c for c in str(i)])
        dp[i] = 1 + dp[i - int(aux[-1])]

print(dp[n])