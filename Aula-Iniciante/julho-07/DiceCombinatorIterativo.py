import sys
input = sys.stdin.readline
mod = 10**9+7
n = int(input())
#armazena as respostas
dp = [0]*(n+1)
#caso base
dp[0] = 1
#calcula os demais
for i in range(1, n+1):
    #considera as 6 faces do dado
    for face in range(1, 7):
        #só soma se o valor não for negativo
        if i - face >= 0:
            #recorrência
            dp[i] = (dp[i] + dp[i-face]) % mod
print(dp[n]) #imprime a resposta