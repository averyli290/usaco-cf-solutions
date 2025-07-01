'''
Avery Li
2/23/2025
'''

def sta():
    n = int(input())
    s = input()
    cur = '1'
    total = 0
    for i in range(n):
        if s[i] == cur:
            total += 1
            cur = '1' if cur == '0' else '0'
    return total

for _ in range(int(input())):
    print(sta())