def backtrack(index, atual, n, k, res):
    if len(atual) == k:
        res.append(atual[:])
        return
    for i in range(index, n+1):
        atual.append(i)
        backtrack(i+1, atual, n, k, res)
        atual.pop()

n = int(input())
k = int(input())
res = []
backtrack(1, [], n, k, res)
print(res)