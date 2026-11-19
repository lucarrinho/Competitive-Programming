from sys import stdin
n, d = map(int, stdin.readline().split())
amigos = []
for _ in range(n):
    m, s = map(int, stdin.readline().split())
    amigos.append((s, m))
amigos.sort(reverse=True)

amizadeMaior = 0
for l in range(len(amigos)):
    amizade = 0
    amigos[0], amigos[l] = amigos[l], amigos[0]
    s, m = amigos[0]
    amizade += s
    maior, menor = m, m
    for i in range(1, len(amigos)):
        s, m = amigos[i]
        if abs(m - menor) < d and abs(maior - m) < d:
            amizade += s
            if m < menor:
                menor = m
            elif menor > maior:
                maior = m
        else: print("excedeu d: ", m, s, "maior: ", maior, "menor: ", menor)
    amizadeMaior = max(amizadeMaior, amizade)
    amigos[0], amigos[l] = amigos[l], amigos[0]
print(amizadeMaior)