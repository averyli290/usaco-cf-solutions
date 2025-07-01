import sys
def sta():
    n = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))
    a = sorted(a)
    if n >= 2:
        sys.stdout.write(str((n - 1) * (a[-1] - a[0])))
    else:
        sys.stdout.write('0')
    sys.stdout.write('\n')


for _ in range(int(input())):
    sta()