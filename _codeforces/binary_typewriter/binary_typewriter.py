from collections import defaultdict
def sta():
    n = int(input())
    s = input()

    prev = '0'
    total = 0
    switch = 0
    for i in range(n):
        if s[i] != prev:
            prev = s[i]
            total += 1
            switch += 1
        total += 1
    
    if switch >= 2:
        total -= 1
    if switch >= 3:
        total -= 1
    
    return total

for _ in range(int(input())):
    print(sta())