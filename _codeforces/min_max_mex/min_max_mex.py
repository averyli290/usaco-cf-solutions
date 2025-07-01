'''
Avery Li
4/8/2025
Problem link: https://codeforces.com/contest/2093/problem/E
'''

import sys


def sta():
    n, k = list(map(int, sys.stdin.readline().strip().split()))
    a = list(map(int, sys.stdin.readline().strip().split()))

    # binary search on mininum of mexes of partitions
    # max of minimum of mexes over all paritions is (n // k) + 1
    l = 0
    r = n // k + 1

    while l < r:
        x = (l + r + 1) // 2

        # check valid using greedy
        s = set()
        s_count = 0
        for i in range(n):
            if a[i] < x:
                s.add(a[i])
            if len(s) >= x:
                s.clear()
                s_count += 1

        # must have at least k sets
        if s_count >= k:
            l = x
        else:
            r = x - 1
    
    return l



for _ in range(int(input())):
    print(sta())