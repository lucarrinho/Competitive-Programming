import sys
input = sys.stdin.readline

def formavel(n):
    while True:
        y = int("1"* len(str(n)))
        if y > n:
            y //= 10
        if y < 11:
            return False
        n -= y
        if n == 0:
            return True
        

t = int(input())
for _ in range(t):
    x = int(input())
    if formavel(x):
        print("YES")
    else:
        print("NO")