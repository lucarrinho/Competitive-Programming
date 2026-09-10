# calcula n-ésimo termo
def termo_pa(a1, r, n):
    return a1 + (n-1)*r

# calcula a soma da PA
def soma_pa(a1, r, n):
    an = termo_pa(a1, r, n)
    return n*(a1 + an) // 2