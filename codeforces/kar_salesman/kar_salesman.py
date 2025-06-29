
import math
def sta():
    n, x  = list(map(int, input().split(' ')))
    a = list(map(int, input().split(' ')))
    x = min(n, x)

    return max(math.ceil(sum(a) / x), max(a))

for _ in range(int(input())):
    print(sta())