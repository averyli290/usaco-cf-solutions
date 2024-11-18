import sys
from collections import defaultdict
import heapq

n = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().strip().split()))

# heap: (number of indices that could support number, number, indices (set) )

d = defaultdict(set)
for i in range(n):
    rep = list(bin(arr[i])[2:])
    d[int(''.join(rep), base=2)].add(i)
    for j in range(len(rep)):
        if rep[j] == '1':
            rep[j] = '0'
        else:
            rep[j] = '1'
        d[int(''.join(rep), base=2)].add(i)
        if rep[j] == '1':
            rep[j] = '0'
        else:
            rep[j] = '1'

print(d)
heap = []
for i in range(1, n + 1):
    heapq.heappush(heap, [len(d[i]), i, d[i]])

done = False
while heap and not done:
    num_ind, num, indices = heapq.heappop(heap)
    if num_ind == 0:
        done = True
    else:
        idx = list(indices)[0]
        for element in heap:
            if idx in element[2]:
                element[2].remove(idx)
                element[0] -= 1
        heapq.heapify(heap)

if len(heap) > 0:
    sys.stdout.write("No\n")
else:
    sys.stdout.write("Yes\n")