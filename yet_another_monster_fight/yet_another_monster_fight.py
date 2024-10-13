# https://codeforces.com/contest/1901/problem/D

'''
Iterate over each monster i, find the min power needed to kill all 
monsters starting at that monster.
'''

n = int(input())
a = list(map(int, input().split(' ')))

prefix_max = [0 for i in range(n)]
suffix_max = [0 for i in range(n)]
p_max = 0
s_max = 0

for j in range(n):
    p_max = max(p_max, a[j] + n - j)
    s_max = max(s_max, a[j] + j - 1)
    prefix_max[j] = p_max
    suffix_max[j] = s_max

ans = 0
print(prefix_max, suffix_max)

for i in range(n):
    power = max(a[i], max(prefix_max[i], suffix_max[i]))
    ans = max(power, ans)

print(ans)

'''
# TLE solution

n = int(input())
a = list(map(int, input().split(' ')))


ans = 10e10

for i in range(n):
    power = a[i]
    for j in range(n):
        if j < i:
            # Everything to right of i and then left to j
            power = max(power, a[j] + (n - i - 1) + (i - j))
        elif j > i:
            # Everything to left of i and then right to j
            power = max(power, a[j] + j)
    ans = min(power, ans)

print(ans)
'''


'''
# Incorrect solution

It is always optimal to start with the highest health monster

Take the worst case scenario at each step, use heap (PriorityQueue)
to select the worst case, which is killing the lowest possible health
monster.

Solve for optimal first choice, worst case outcome.

'''
'''
from queue import PriorityQueue 

n = int(input())
a = list(map(int, input().split(' ')))
m_idx = 0
for i in range(n):
    if a[i] > a[m_idx]:
        m_idx = i

visited = [0 for i in range(n)]
visited[m_idx] = 1

p = PriorityQueue()
p.put((a[m_idx], m_idx))

min_power = a[m_idx]
counter = 0

while not p.empty():
    cur = p.get()
    cur_idx = cur[1]

    if cur[0] + counter > min_power:
        min_power = cur[0] + counter

    #print(cur, min_power, counter)

    if cur_idx - 1 >= 0:
        if not visited[cur_idx - 1]:
            visited[cur_idx - 1] = 1
            p.put((a[cur_idx - 1], cur_idx - 1))
    if cur_idx + 1 < n:
        if not visited[cur_idx + 1]:
            visited[cur_idx + 1] = 1
            p.put((a[cur_idx + 1], cur_idx + 1))
    counter += 1

print(min_power)
'''
