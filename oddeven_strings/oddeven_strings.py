import sys
from collections import defaultdict

def sta():
    d = defaultdict(int)
    for i in input():
        d[i] += 1
    even = True
    odd = True
    for i in d:
        if d[i] % 2 == 0: odd = False
        else: even = False
    if even:
        print(0)
    elif odd:
        print(1)
    else:
        print('0/1')

sta()
