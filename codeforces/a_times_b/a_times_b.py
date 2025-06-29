import sys
def sta():
    a, b, n, m = map(int, sys.stdin.readline().strip().split())
    total = 0
    #print()
    #print(a,b,n,m)
    while a < n or b < m:
        total += a * b
        if (a < b and a < n) or b == m:
            a += 1
        else:
            b += 1
        #print(a, b)
    total += m * n
    
    sys.stdout.write(str(total) + '\n')




for _ in range(int(input())):
    sta()