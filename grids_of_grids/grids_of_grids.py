import sys
from collections import defaultdict


def sta():
    n, m = list(map(int, sys.stdin.readline().strip().split()))

    d = defaultdict(int)
    empty = "."*m*m
    d[empty]= 0 

    for i in range(n):
        s = ""
        for j in range(m):
            s += sys.stdin.readline().strip()
        d[s] += 1
    
    
    
    total = 0
    for k in d:
        total += d[k] * (d[k] - 1) // 2
        if k != empty:
            total += d[k] * d[empty]
    sys.stdout.write(str(total)+'\n')


sta()
