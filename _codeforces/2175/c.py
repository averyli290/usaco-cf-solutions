import sys
from collections import defaultdict

def sta():
    s = input()
    t = input()
    a = defaultdict(int)
    b = defaultdict(int)
    for c in s:
        a[c] += 1
    for c in t:
        b[c] += 1

    for c in a:
        if a[c] > b[c]:
            print("Impossible")
            return
        b[c] -= a[c]

    d = sorted([i for i in "qwertyuiopasdfghjklzxcvbnm"])
    ans = ""
    ctr = 0
    for c in d:
        while ctr < len(s) and c >= s[ctr]:
            ans += s[ctr]
            ctr += 1
        ans += c * b[c]
    if ctr < len(s):
        ans += s[ctr:]
    print(ans)


for _ in range(int(input())):
    sta()