from sys import stdin
input = stdin.readline

def binarySearch(v, key,start, end):
    while start < end:
        mid = (start + end) // 2
        if v[mid][0] < key:
            start = mid+1
        if v[mid][0] >= key:
            end = mid
    return v[mid][0]

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

aux = [(b[i], i) for i in range(m)]
aux.sort()

for i in range(0):
    j = binarySearch(aux, a[i], 0, m-1)
    if j == -1:
        continue
    for x in range(n-1, j-1, -1):
        k = aux.pop()[1]
        b[k] = i

#for n in b:
    #print(n)

print(binarySearch(aux, 2, 0, m-1))