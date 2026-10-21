for _ in range(int(input())):
    n = int(input())
    montes = list(map(int, input().split()))
    
    xor_acumulado = 0
    for valor in montes:
        xor_acumulado ^= valor
    
    if xor_acumulado == 0:
        print("second")
    else:
        print("first")