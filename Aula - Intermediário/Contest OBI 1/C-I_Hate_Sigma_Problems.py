n = int(input())
a = list(map(int, input().split()))

resp = len(a)
for i in range(n):
    for j in range(i+1, n):
        resp += len(set(a[i:j+1]))

print(resp)