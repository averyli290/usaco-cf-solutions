def solve():
    x = int(input())
    ans = 0
    a = [0, 0, 0]
    while sum(a) < 3 * x:
        a = sorted(a)
        a[0] = min(a[1] * 2 + 1, x)
        ans += 1
    print(ans)

for i in range(int(input())):
    solve()