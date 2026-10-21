from math import sqrt
def calcula_quadrado_dist(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x2 - x1)**2 + abs(y2 - y1)**2

p = []
for _ in range(3):
    x, y = map(int, input().split())
    p.append((x, y))

l_a = calcula_quadrado_dist(p[0], p[1])
l_b = calcula_quadrado_dist(p[1], p[2])
l_c = calcula_quadrado_dist(p[0], p[2])

if (l_a + l_b == l_c):
    print("Yes")
elif (l_b + l_c == l_a):
    print("Yes")
elif (l_c + l_a == l_b):
    print("Yes")
else:
    print("No")