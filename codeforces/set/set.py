import sys
def sta():
    l, r, k = list(map(int, sys.stdin.readline().strip().split()))

    sys.stdout.write(str(max(r // k - l + 1, 0)) + '\n')


for _ in range(int(input())):
    sta()