def main():
    n_pedras = int(input())
    pesos = [int(n) for n in input().split()]
    
    while True:
        pesos.sort()
        if not len(pesos) > 1:
            break
        diferenca = abs( - maior2)
        if diferenca > 0:
            pesos.append(diferenca)
    
    print(pesos)

main()