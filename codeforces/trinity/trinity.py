import sys
def sta():
    n = int(sys.stdin.readline().strip())
    a = sorted(list(map(int, sys.stdin.readline().strip().split())))
    i = 0
    j = n - 1
    ans = 0
    while j - i >= 2:
        if a[i] + a[i + 1] <= a[j]:
            if a[i + 1] - a[i] > a[j] - a[j - 1]:
                pass
            else:
                j -= 1
            ans = n - j + i - 1
        i += 1
        
    sys.stdout.write(str(ans) + '\n')
 
for _ in range(int(input())):
    sta()