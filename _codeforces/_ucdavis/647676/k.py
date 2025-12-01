import sys

def sta():
    n, a, b = list(map(int, sys.stdin.readline().strip().split()))
    if a + b - 1 > n:
        print('no')
        return
    if a == 1 and b == 1:
        print('no')
        return
    
    print('yes')
    ans = []
    for i in range(n-a+1, n):
        ans.append(str(i))
    for i in range(1, n-a-b+2):
        ans.append(str(i))
    for i in range(n-a, n-a-b+1, -1):
        ans.append(str(i))
    if b == 1:
        ans.append(str(n))
    else:
        ans.insert(a-1, str(n))
    print(' '.join(ans))

sta()