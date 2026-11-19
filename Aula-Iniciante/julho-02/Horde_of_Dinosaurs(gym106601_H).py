from sys import stdin
n = int(stdin.readline())
dino = []
for _ in range(2*n):
    x, y = map(int, stdin.readline().split())
    dino.append((x+y, x, y))
dino.sort()

x = 0
y = 0
for i in range(n):
    y += dino[i][2]
    x += dino[(2*n)-1-i][1]

print(x-y)

# O problema sou eu #
#n = int(input())
#ganhos = []
#resposta = 0
#for _ in range(2*n):
#    x, y = map(int, input().split())
#    resposta -= y
#    ganhos.append(x+y)
#ganhos.sort(reverse=True)
#for i in range(n):
#    resposta += ganhos[i]
#print(resposta)