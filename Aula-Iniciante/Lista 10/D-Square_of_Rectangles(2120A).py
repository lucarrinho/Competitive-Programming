for _ in range(int(input())):
    l1, b1, l2, b2, l3, b3 = map(int, input().split())
    
    resultado = "NO"
    if l1 == l2 == l3 and b1 + b2 + b3 == l1:
            resultado = "YES"
    elif b1 == b2 == b3 and l1 + l2 + l3 == b1:
            resultado = "YES"
    elif l1 + l2 == l3 and b1 == b2 and b1 + b3 == l3:
            resultado = "YES"
    elif l1 + l3 == l2 and b1 == b3 and b1 + b2 == l2:
            resultado = "YES"
    elif l2 + l3 == l1 and b2 == b3 and b2 + b1 == l1:
            resultado = "YES"
    elif b1 + b2 == b3 and l1 == l2 and l1 + l3 == b3:
            resultado = "YES"
    elif b1 + b3 == b2 and l1 == l3 and l1 + l2 == b2:
            resultado = "YES"
    elif b2 + b3 == b1 and l2 == l3 and l2 + l1 == b1:
            resultado = "YES"
    print(resultado)