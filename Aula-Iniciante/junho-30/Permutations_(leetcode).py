from sys import setrecursionlimit
setrecursionlimit(10000)

# https://leetcode.com/problems/permutations/description/
# incompleto
def backtrack(nums, usado, permutacao_atual, todas_permutacoes):
    if len(permutacao_atual) == len(nums):
        todas_permutacoes.append(permutacao_atual)
    for i in range(len(nums)):
        if usado[i]:
            continue
        usado[i] = True
        permutacao_atual.append(nums[i])
        backtrack(nums, usado, permutacao)
        permutacao_atual.append(nums[i])
        backtrack(caminho_atual, prox_num, res, n)
        caminho_atual.pop()

n = int(input())
nums = list(map(int, input().split()))
usado = [False]*n
permutacao_atual = []
todas_permutacoes = []
backtrack(nums, usado, permutacao_atual, todas_permutacoes)
print(len(res))
for s in res:
    print(s)