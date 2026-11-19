def main():
    m, n = [int(n) for n in input().split()]
    account = []
    maiorSaldo = 0
    for _ in range(m):
        cliente = [int(n) for n in input().split()]
        saldo = sum(cliente)
        account.append(cliente)
        if saldo > maiorSaldo:
            maiorSaldo = saldo
    
    print(maiorSaldo)

main()