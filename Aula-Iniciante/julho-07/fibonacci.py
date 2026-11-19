def fibonacci(x):
    if x == 0: #caso base fib(0)
        dp[0] = 0
        return 0
    if x == 1: #caso base fib(1)
        dp[1] = 1
        return 1
    if dp[x] != -1: #se já tiver calculado
        return dp[x]
    #recorrência e salva o cálculo
    dp[x] = fibonacci(x-1) + fibonacci(x-2)
    return dp[x]

n = int(input()) #leitura da entrada
dp = [-1]*n #inicializa vetor com -1
resultado = []
for i in range(n): #constrói a saída
    resultado.append(str(fibonacci(i)))
print(" ".join(resultado)) #imprime a saída