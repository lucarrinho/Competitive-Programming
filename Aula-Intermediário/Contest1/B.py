from sys import stdin
input = stdin.readline

n, q = map(int, input().split())
a = list(map(int, input().split()))
xor_acc = [a[0]]*n
for i in range(1, n):
    xor_acc[i] = xor_acc[i-1] ^ a[i]

guardar = []
for _ in range(q):
    t, x, y = map(int, input().split())
    if t == 1:
        for i in range(x-1, n):
            guardar.append(y)
    else:
        saida = xor_acc[y-1]
        for i in range(len(guardar)):
            saida ^= guardar[i]
        if x > 1:
            print(saida ^ xor_acc[x-2])
        else:
            print(saida)