#leitura da entrada
nums = [0] + list(map(int, input())) #coloca casa 0 para facilitar
n = len(nums)-1 #tamanho da entrada
#armazena a resposta
dp = [-1]*(n+1)
#caso base
dp[0] = 0
if n >= 1:
    dp[1] = nums[1]
#calcula os demais casos
for i in range(2, n+1):
    #recorrência
    dp[i] = max(dp[i-1], dp[i-2]+nums[i])
print(dp[n])#imprime a saída