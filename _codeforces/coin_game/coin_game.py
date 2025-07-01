def sta():
    n = int(input())
    s = input()

    return "YES" if [c for c in s].count('U') % 2 == 1 else "NO"


for _ in range(int(input())):
    print(sta())