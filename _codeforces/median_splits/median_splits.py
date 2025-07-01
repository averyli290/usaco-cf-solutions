'''
Avery Li
4/21/2025
Problem link: https://codeforces.com/contest/2103/problem/C
'''

import sys

def s(arr, k):
    g = 0
    le = 0
    m = len(arr)
    for i in range(len(arr)):
        if arr[i] > k:
            g += 1
        else:
            le += 1
        if i % 2 == 0 and le >= g + 1:
            if i < len(arr) - 1 and arr[i + 1] > k:
                return i + 1
            return i
        if i % 2 == 1 and le >= g:
            return i
    return m

def sta():
    n, k = list(map(int, sys.stdin.readline().strip().split()))
    a = list(map(int, sys.stdin.readline().strip().split()))

    #print(a, k)
    first = s(a, k)
    #print("F", first)
    if first < n:
        second = s(a[first + 1:], k)
        #print("S", second)
        if second < n - (first + 1):
            return "YES"
        second = s(a[first + 1:][::-1], k)
        #print("S", second)
        if second < n - (first + 1):
            return "YES"
    a = a[::-1]
    first = s(a, k)
    #print("F", first)
    if first < n:
        second = s(a[first + 1:], k)
        #print("S", second)
        if second < n - (first + 1):
            return "YES"
        second = s(a[first + 1:][::-1], k)
        #print("S", second)
        if second < n - (first + 1):
            return "YES"

    return "NO"
    # # 6 8
    # # 7 11 12 4 9 17
    # # 17 9 4 12 11 7
    # # 17 9 4
    # return "NO"
    


for _ in range(int(input())):
    print(sta())