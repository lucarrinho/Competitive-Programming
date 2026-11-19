from sys import setrecursionlimit

def backtrack(caminho_atual, nums, res, n):
    if len(caminho_atual) == n:
        res.append(caminho_atual)
    for i in range(len(nums)):
        caminho_atual.append(nums[i])
        prox_num = nums[:i] + nums[i+1:]
        backtrack(caminho_atual, prox_num, res, n)
        caminho_atual.pop()

nums = list(map(int, input().split()))
res = []
backtrack([], nums, res, len(nums))
print(len(res))
for s in res:
    print(s)