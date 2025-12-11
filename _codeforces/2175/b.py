import sys

def sta():
    n, l, r = list(map(int, sys.stdin.readline().strip().split()))
    l -= 1
    r -= 1
    ans = [0] * n
    ans[l] = 1
    ans[r] = 2
    cur = 513
    ctr = 0
    ctr2 = 0
    for i in range(l):
        if ctr % 2 == 0:
            ans[i] = cur
        else:
            ans[i] = 1 << (3 + ctr2 % 3)
            ctr2 += 1
        cur += 1
        ctr += 1
    temp = 3
    ctr2 = 0
    for i in range(l + 1, r - 1):
        if ctr % 2 == 0:
            ans[i] = cur
        else:
            ans[i] = 1 << (3 + ctr2 % 3)
            ctr2 += 1
        cur += 1
        ctr += 1
        temp ^= ans[i]
    ans[r - 1] = temp

    if (ctr % 2 == 1):
        cur += 1
    ctr = 0
    ctr2 = 0
    for i in range(r + 1, n):
        if ctr % 2 == 0:
            ans[i] = cur
        else:
            ans[i] = 1 << (3 + ctr2 % 3)
            ctr2 += 1
        cur += 1
        ctr += 1

    if (l == r - 1):
        ans[l] = 1
        ans[r] = 1

    print(*ans)



for _ in range(int(input())):
    sta()