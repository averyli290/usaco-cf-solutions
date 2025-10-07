import sys
import heapq


'''

10 3 8 2 9
10 8 2 9 4
10 2 9 4 9
10 2 4 9 10
2 4 9 10 11

10 3 8 2 9
10 8 2 9 4
10 2 9 4 9
10 2 4 9 10
2 4 9 10 11

2 4 9 10 11

any increasing values that aren't sorted in prefix should be reversed ?

'''

def sta():
    n = list(map(int, sys.stdin.readline().strip().split()))[0]
    a = list(map(int, sys.stdin.readline().strip().split()))

    b = [(a[i], 0) for i in range(n)]
    heapq.heapify(b)

    ctr = 0
    ans = []

    while ctr < n:
        cur, itr = heapq.heappop(b)
        print(a)
        # print(ctr, n)
        if itr < ctr:
            continue
        temp = []
        new = []
        j = 0
        for i in range(len(a)):
            if a[i] == cur:
                break
            j += 1
            temp.append(a[i])
        temp = sorted(temp)
        for i in range(len(temp)):
            temp[i] += 1
            heapq.heappush(b, (temp[i], ctr + 1))
        for i in range(j + 1, len(a)):
            heapq.heappush(b, (a[i], ctr + 1))
        new = a[j + 1:] + temp
        a = new
        ans.append(cur)
        ctr += 1
    return ' '.join([str(i) for i in ans])

for _ in range(int(input())):
    print(sta())