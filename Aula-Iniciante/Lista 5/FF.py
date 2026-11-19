n, q = map(int, input().split())

seguido_por = {}

for _ in range(q):
    t, a, b = map(int, input().split())
    
    if t == 1:
        if a not in seguido_por:
            seguido_por[a] = set()
        seguido_por[a].add(b) 
    
    elif t == 2:
        if a in seguido_por:
            seguido_por[a].discard(b)
    
    elif t == 3:
        if a in seguido_por and b in seguido_por:
            if a in seguido_por[b] and b in seguido_por[a]:
                print("Yes")
            else:
                print("No")
        else:
            print("No")