def exp_rapida(a, b, mod):
    res = 1
    while b > 0: #enquanto tivermos expoente
        # se o expoente atual for impar
        if b % 2 == 1: # op => usar mod m em res
            res = (res*a)%mod
            # elevamos a base ao quadrado
        a = (a*a)%mod
        b //= 2
        return res