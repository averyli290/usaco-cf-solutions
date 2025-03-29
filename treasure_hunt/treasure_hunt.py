def sta():
    x, y, a = list(map(int, input().strip().split()))
    a %= x + y
    a -= x
    if a < 0:
        return "NO"
    else:
        return "YES"

for _ in range(int(input())):
    print(sta())