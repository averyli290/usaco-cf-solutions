import sys

l, r = list(map(int, sys.stdin.readline().strip().split()))
total = 2 * (l + r)

if l == r or l == r+2:
    print(total * 3 // 4)
elif l == r+1:
    print(total // 2)
else:
    print(total)