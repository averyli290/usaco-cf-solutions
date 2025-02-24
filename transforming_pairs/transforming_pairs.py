from collections import deque, defaultdict

def sta():
    a, b, c, d = map(int, input().split())

    steps = 0
    while c >= a and d >= b:
        if c == a and d == b:
            return steps
        if c > d:
            dec = (c - a) // d 
            if dec == 0:
                return -1
            steps += dec
            c -= dec * d
        else:
            dec = (d - b) // c
            if dec == 0:
                return -1
            steps += dec
            d -= dec * c
    return -1
    

for _ in range(int(input())):
    print(sta())