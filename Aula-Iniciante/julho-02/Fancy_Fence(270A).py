t = int(input())
for _ in range(t):
    a = int(input())
    if (360 % (180 - a) == 0):
        print("YES")
    else:
        print("NO")