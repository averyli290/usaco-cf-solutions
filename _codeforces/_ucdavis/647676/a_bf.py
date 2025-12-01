import sys

# l, r = list(map(int, sys.stdin.readline().strip().split()))

def sta(l, r):
    a = list(range(1, l + 1))
    b = list(range(a[-1] + 1, r + a[-1] + 1))

    pairs = set()
    pairs2 = set()
    for i in range(10):
        pairs.add((a[-1], b[-1]))
        pairs2.add((min(a[-1], b[-1]), max(a[-1], b[-1])))
        b.insert(0, a.pop())
        # print(a, b)
        pairs.add((a[-1], b[-1]))
        pairs2.add((min(a[-1], b[-1]), max(a[-1], b[-1])))
        a.insert(0, b.pop())
        # print(a, b)
    return pairs2

def sta2(l, r):
    total = 2 * (l + r)

    if l == r or l+2 == r:
        return total * 3 // 4
    elif l+1 == r:
        return total // 2
    else:
        return total

for l in range(2, 10):
    for r in range(1, 10):
        ans1 = len(sta(l, r))
        ans2 = sta2(l, r)
        if ans1 != ans2:
            print(l, r, ans1, ans2)