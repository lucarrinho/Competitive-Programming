def eh_colinear(p1, p2, p3):
    x1, y1 = p1
    x2, y2 = p2
    x3, y3 = p3
    return (x1-x2)*(y3-y1)==(x3-x1)*(y1-y2)
    

n = int(input())
p = []
for _ in range(n):
    x, y = map(int, input().split())
    p.append((x, y))

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            if eh_colinear(p[i], p[j], p[k]):
                print("Yes")
                exit()
print("No")