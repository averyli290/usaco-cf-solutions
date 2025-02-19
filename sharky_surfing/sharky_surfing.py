import sys

def sta():
    n, m, L = list(map(int, sys.stdin.readline().strip().split()))
    intervals = [(0,0) for _ in range(n)]
    powerups = [(0,0) for _ in range(m)]

    # take the lowest amount of powerups to make any given jump
    # prefix sums on the available jumps before each given interval

    for i in range(n):
        intervals[i] = list(map(int, sys.stdin.readline().strip().split()))
    for i in range(m):
        powerups[i] = list(map(int, sys.stdin.readline().strip().split()))
    i = 0
    p = 0
    ans = 0
    jump_power = 1



    while i < n:
        cur_group = []
        while p < m and powerups[p][0] < intervals[i][0]:
            cur_group.append(powerups[p][1])
            p += 1
        cur_group = sorted(cur_group, key=lambda x: -x)
        distance = intervals[i][1] - intervals[i][0] + 1
        print(cur_group, distance)
        used = 0
        while distance - jump_power > 0 and used < len(cur_group):
            jump_power += cur_group[used]
            used += 1
            ans += 1
        if distance - jump_power > 0:
            sys.stdout.write('-1\n')
            return
        i += 1

    sys.stdout.write(str(ans) + '\n')

for _ in range(int(input())):
    sta()