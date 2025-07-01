import sys
from collections import defaultdict
def sta():
    n, m = list(map(int, sys.stdin.readline().strip().split()))
    x = list(map(int, sys.stdin.readline().strip().split()))
    r = list(map(int, sys.stdin.readline().strip().split()))

    def calc(r, offset):
        l = 0
        h = r
        while l < h:
            m = (l + h + 1) // 2
            v = m * m + offset * offset 
            if v == r * r:
                return m
            elif v < r * r:
                l = m
            else:
                h = m - 1
        return l

    # f = defaultdict(int)
    # for i in range(n):
    #     for j in range(-r[i], r[i] + 1):
    #         f[j + x[i]] = max(f[j + x[i]], calc(r[i], j))
    # ans = 0
    # for k in f:
    #     ans += f[k] * 2 + 1
    # print(f)
    #return ans

    d ={}
    for i in range(n):
        for j in range(-r[i], r[i] + 1):
            if j + x[i] not in d:
                d[j + x[i]] = (x[i], r[i])
            else:
                cen, rad = d[j + x[i]]
                if r[i] * r[i] - j * j > rad * rad - (j + x[i] - cen) * (j + x[i] - cen):
                    d[j + x[i]] = (x[i], r[i]) 

    ans = 0
    #print(d)
    for k in d:
        v = d[k]
        ans += calc(v[1], k - v[0]) * 2 + 1

    return ans
    
for _ in range(int(input())):
    print(sta())