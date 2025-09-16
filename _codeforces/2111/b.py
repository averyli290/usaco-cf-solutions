# Problem link: https://codeforces.com/contest/2111/problem/B

def solve():
    n, m = list(map(int, input().strip().split()))
    ans = [0] * m
    fib1 = 1
    fib2 = 2
    for i in range(n - 2):
        fib3 = fib1 + fib2
        fib1 = fib2
        fib2 = fib3
    for i in range(m):
        w, h, l = list(map(int, input().strip().split()))
        dims = sorted([w, h, l])
        if (fib2 > dims[0]):
            ans[i] = 0
            continue
        if (fib2 + fib1 > dims[2]):
            ans[i] = 0
            continue
        ans[i] = 1
    print(''.join([str(i) for i in ans]))

for i in range(int(input())):
    solve()