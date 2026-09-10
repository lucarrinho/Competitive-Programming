import sys

n, m = map(int, sys.stdin.readline().split())
turma = [0]*m
for _ in range(n):
    g = list(map(int, sys.stdin.readline().split()))
    for j in range(m):
        turma[j] = max(turma[j], g[j])

print(sum(turma))