import sys
import heapq
from collections import defaultdict

def sta():
    n, k, p = list(map(int, sys.stdin.readline().strip().split()))
    m = int(sys.stdin.readline().strip())
    s = list(map(int, sys.stdin.readline().strip().split()))

    for i in range(m):
        s[i] += 1

    last_used = [-1 for i in range(k + 2)]
    freq = defaultdict(int)
    for i in range(m):
        freq[s[i]] += 1
        last_used[s[i]] = i

    q = []
    #for num in freq:
    #    heapq.heappush(q, (freq[num], last_used[num], num))
    
    for num in range(1, k + 1):
        heapq.heappush(q, (freq[num], last_used[num], num))

    for i in range(m, n):
        cur_freq, last_used_time, cur_num = heapq.heappop(q)
        s.append(cur_num)
        
        freq[cur_num] += 1
        heapq.heappush(q, (freq[cur_num], last_used_time + p, cur_num))

    sys.stdout.write(' '.join(map(str, [i for i in s])) + '\n')

sta()
