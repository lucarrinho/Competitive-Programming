import sys
input = sys.stdin.readline

def combinations(x):
    if x == 0:
        return 1
    if x < 0:
        return 0
    if dp[x] != -1:
        return dp[x]
    total = 0
    for dado in [1, 2, 3, 4, 5, 6]:
        total = (total + combinations(x - dado)) % mod
    dp[x] = total
    return total

n = int(input())
mod = 10**9+7
dp = [-1]*(n+1)
print(combinations(n))