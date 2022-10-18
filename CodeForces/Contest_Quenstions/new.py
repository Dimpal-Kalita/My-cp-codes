for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    l = 1
    ans = 0
    for x in a:
        if l > x:
            ans += l * (l-1) // 2
            l = x
            ans -= l * (l-1) // 2
        l += 1
    ans += l * (l-1)// 2
    print(ans)