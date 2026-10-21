import sys
input = sys.stdin.readline

def da(s):
    zeros = 0
    uns = 0
    for c in s:
        if c == "0":
            zeros += 1
        elif c == "1":
            uns += 1
    if min(zeros, uns) % 2 == 0:
        return False
    return True

t = int(input())
for _ in range(t):
    s = input()
    if da(s):
        print("DA")
    else:
        print("NET")