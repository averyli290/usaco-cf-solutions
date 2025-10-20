import sys

_ = sys.stdin.readline()
a = list(map(int, sys.stdin.readline().strip().split()))

x = a[0] // 3
y = a[1] - a[0] + x
z = a[-1] // 3

print(f'{x} {y} {z}')