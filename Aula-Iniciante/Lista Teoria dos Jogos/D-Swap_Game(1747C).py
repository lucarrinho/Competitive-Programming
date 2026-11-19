t = int(input())

for _ in range(t):
    n = int(input())
    array = list(map(int, input().split()))
    
    if array[0] == 1:
        print("Bob")
    else:
        print("Alice")