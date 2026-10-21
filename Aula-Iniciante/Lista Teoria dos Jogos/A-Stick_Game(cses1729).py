n, k = map(int, input().split())
jogadas = list(map(int, input().split()))

s = ["L"]*(n+1)
for i in range(1, n+1):
    for p in jogadas:
        prox = i - p
        if (prox >= 0) and s[prox] == "L":
            s[i] = "W"
            break

print("".join(s[1::]))