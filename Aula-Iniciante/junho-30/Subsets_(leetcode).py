def backtrack(start_index, caminho_atual, nums, res):
    # 1. Caso base: Toda chamada é um subconjunto válido
    res.append(caminho_atual[:]) # [:] faz cópia da lista
    # 2. Tentar todas as escolhas possíveis a partir de start_ind
    for i in range(start_index, len(nums)):
        # 3. Verificar se essa escolha é válida: toda escolha é válida
        # 4. Fazer a escolha: adiciona nums[i] ao subconjunto total
        caminho_atual.append(nums[i]) # Empilha escolha
        # 5. Explorar: considerar elementos depois de nums[i]
        backtrack(i+1, caminho_atual, nums, res)
        # 6. Desfazer escolha: remove o último elemento adicionado
        caminho_atual.pop() # Desempilha a escolha

# Leitura de entrada: lista de números
nums = list(map(int, input().split()))
res = [] # Armazenará a saída
backtrack(0, [], nums, res) # Faz a busca
print(len(res)) # Imprime tamanho
for s in res: # Imprime elementos
    print(s)