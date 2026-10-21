# https://leetcode.com/problems/n-queens/description/

def backtrack(tabuleiro_atual, n_rainhas, solucoes, tabuleiro, n):
    if n_rainhas == n:
        solucoes.append(tabuleiro_atual)
    

n = int(input())
tabuleiro = ["."*n]*n
solucoes = []