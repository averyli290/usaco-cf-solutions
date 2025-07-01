'''
Avery Li
4/24/2025
Problem link: https://codeforces.com/contest/2106/problem/A
'''

import sys

def sta():
    n = int(input())
    a = input()
    x = a.count('1')
    y = a.count('0')
    print(x, y)
    return x * (n - 1) + y


for _ in range(int(input())):
    print(sta())