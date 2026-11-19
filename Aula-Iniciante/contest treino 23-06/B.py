#testar em c++

n, k = map(int, input().split())
muralha = list(map(int, input().split()))

maior = 0
for i in range(n):
    pedras = k
    nova = muralha.copy()
    for j in range(n-i-1, -1, -1):
        nova[j] += pedras
        pedras -= 1
        if pedras == 0:
            break
    maior = max(maior, min(nova))

print(maior)