import sys

def sta():
    k = int(input())
    a = sorted(list(map(int, input().split(' '))))
    l = 0
    r = k - 1
    while a[l] * a[r] != k - 2:
        if a[l] * a[r] < k - 2:
            l += 1
        else:
            r -= 1
    
    sys.stdout.write(str(a[l]) + ' ' + str(a[r]) + '\n')


for _ in range(int(input())):
    sta()