for _ in range(int(input())):
    n = int(input())
    s = input()
    ct = 0
    check = 1
    for i in range(n):
        if s[i] == '1':
            ct ^= 1
        else:
            if ct:
                check = 0
                print("NO")
                break
            ct = 0
    if check:
        if ct:
            print("NO")
            continue
        print("YES")