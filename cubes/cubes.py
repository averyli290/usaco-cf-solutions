import sys

n, r, g, b = list(map(int, sys.stdin.readline().strip().split()))


dp_r = [1 if i < r else 0 for i in range(n)]
dp_g = [1 if i < g else 0 for i in range(n)]
dp_b = [1 if i < b else 0 for i in range(n)]

sliding_r = 0
sliding_g = 0
sliding_b = 0

for i in range(1, n):
    # add last r, g, b from each of the other ones
    dp_r[i] = sliding_b + sliding_g
    dp_g[i] = sliding_r + sliding_b
    dp_b[i] = sliding_r + sliding_g


    # dp_r[i] = dp_g[i - 1] + dp_b[i - 1]
    # dp_g[i] = dp_r[i - 1] + dp_b[i - 1]
    # dp_b[i] = dp_g[i - 1] + dp_r[i - 1]

print(dp_b[-1] + dp_r[-1] + dp_g[-1])
print(dp_b)
print(dp_r)
print(dp_g)

#6 1 3 3

# dp_r: 1
# dp_g: 1 1 1
# dp_b: 1 1 1
#

#print(n, r, g, b)