'''
Avery Li
3/17/2025
Problem link: https://codeforces.com/contest/2075/problem/C
'''

def sta():
    n, m = list(map(int, input().strip().split()))
    l = sorted(list(map(int, input().strip().split())), reverse=True)

    c = 1
    while (c < m and l[c] + l[c - 1] >= n):
        c += 1
    

    print(l)
    print("c", c)
    ans = 0
    for i in range(1, c):
        ans += min(n - 1, l[i]) * 2
    return ans
    

for _ in range(int(input())):
    print(sta())