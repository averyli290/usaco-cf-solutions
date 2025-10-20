import sys

def sta():
    n, k = list(map(int, sys.stdin.readline().strip().split()))
    x = [0] * n
    for i in range(n):
        x[i] = int(input())
    x = sorted(x)
    total = 0
    # mu^2-2*mu*x_i+x_i^2
    cur = 0
    for i in range(k):
        total += x[i]
    mu = (total / k)
    for i in range(k):
        cur += (mu - x[i]) * (mu - x[i])
    ans = cur
    # print(cur)
    for i in range(n - k):
        mu = (total / k)
        # print(total, mu)
        cur -= (mu * mu) * k - (2 * mu * total)
        cur -= x[i] * x[i]
        total -= x[i]
        total += x[i + k]
        mu = total / k
        cur += (mu * mu) * k - (2 * mu * total)
        cur += x[i + k] * x[i + k]
        ans = min(ans, cur)
        # print(cur)

    print(ans)

sta()