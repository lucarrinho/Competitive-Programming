def main():
    n, m = [int(n) for n in input().split()]
    matriz = []
    for _ in range(n):
        linha = [int(n) for n in input().split()]
        matriz.append(linha)
    
    transposta = []
    for j in range(m):
        linha = []
        for i in range(n):
            linha.append(matriz[i][j])
        transposta.append(linha)
    
    print(matriz)
    print(transposta)

main()