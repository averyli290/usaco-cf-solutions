'''
Avery Li
4/6/2025
Problem link: https://codeforces.com/group/Agsm1DY0x3/contest/600925/problem/G
'''

def sta():
    n = int(input())
    a = list(map(int, input().strip().split()))

    for i in range(len(a)):
        for j in range((i + 1) * 2, len(a) + 1, i + 1):
            a[j - 1] -= a[i]

    last = 0
    if n - sum(a) > 0:
        last = n - sum(a)
    
    MOD = pow(10, 9) + 7

    factorial = [0] * (n + 1)
    factorial[0] = 1
    for i in range(1, n + 1):
        factorial[i] = factorial[i - 1] * i
        factorial[i] %= MOD
    
    num = factorial[n]
    den = 1

    # count # of permutations for a cycle type
    for i in range(len(a)):
        l = i + 1
        count = a[i] // l

        for i in range(count):
            den *= factorial[l]
            den %= MOD

            num *= factorial[l - 1]
            num %= MOD

        den *= factorial[count]
        den %= MOD
    
    den *= factorial[last]
    den %= MOD

    if last == n:
        return factorial[n - 1]

    return (num * pow(den, -1, MOD)) % MOD


print(sta())