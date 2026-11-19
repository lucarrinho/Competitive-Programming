def main():
    s = [c for c in input()]

    for i in range(len(s)//2):
        s[i], s[len(s)-1-i] = s[len(s)-1-i], s[i]

    print(''.join(s))

main()
