for _ in range(int(input())):
    n, s = map(int, input().split())
    acc = 0
    for _ in range(n):
        dx, dy, x, y = map(int, input().split())
        if (0-x)*(y+dy-0)==(x+dx-0)*(0-y):
            acc += 1
        elif (0-x)*(y+dy-s)==(x+dx-0)*(s-y):
            acc += 1
        elif (s-x)*(y+dy-0)==(x+dx-s)*(0-y):
            acc += 1
        elif (s-x)*(y+dy-s)==(x+dx-s)*(s-y):
            acc += 1
    print(acc)