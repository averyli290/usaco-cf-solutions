# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())

def helper(h, m, s):
    return h * 60 * 60 + m * 60 + s
    
def helper2(x):
    h = str(x // (60 * 60))
    if len(h) == 1:
        h = '0' + h
    x %= 60 * 60
    m = str(x // 60)
    if len(m) == 1:
        m = '0' + m
    x %= 60
    s = str(x)
    if len(s) == 1:
        s = '0' + s
    return h + ":" + m + ":" + s

taken = set()

times = []
for i in range(n):
    h, m, s = list(map(int, input().strip().split(':')))
    x = helper(h, m, s)
    times.append((x, i))
    taken.add(x)

times = sorted(times, key=lambda p: p[0])

ans = [0] * n
#ans = []
if times[-1][0] == helper(23, 59, 59):
    print("IMPOSSIBLE")
else:
    left = 0
    indexes = []
    for i in range(n - 1):
        left += 1
        indexes.append(times[i][1])
        #print(indexes)
        cur = times[i][0] + 1
        while cur != times[i + 1][0] and left > 0:
            if cur not in taken:
                left -= 1
                taken.add(cur)
                #ans.append(cur)
                #print("cur", cur)
                ans[indexes.pop(0)] = cur
            cur += 1
    ans[times[-1][1]] = helper(23, 59, 59)
    if left > 0:
        print("IMPOSSIBLE")
    for i in ans:
        print(helper2(i))
