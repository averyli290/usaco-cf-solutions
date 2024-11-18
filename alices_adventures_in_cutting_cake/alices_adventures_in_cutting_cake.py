import sys

def sta():
    n, m, v = list(map(int, sys.stdin.readline().strip().split(' ')))
    a = list(map(int, sys.stdin.readline().strip().split(' ')))

    # First check if it is possible to get partitions for monster
    cur = 0
    monsters_left = m
    partiton_idxs = []
    for i in range(n):
        cur += a[i]
        if cur >= v:
            monsters_left -= 1
            cur = 0
            partiton_idxs.append(i)
    #print(partiton_idxs)
    if monsters_left > 0:
        sys.stdout.write('-1\n')
        return
    partiton_idxs.insert(0, -1)

    ans = 0
    for i in range(len(partiton_idxs)):
        left = partiton_idxs[i] + 1
        impossible = False
        #right = left
        low = left
        high = n - 1
        while low <= high:
            right = (low + high) // 2
            m_left = m - i
            c = 0
            for j in range(right + 1, n):
                c += a[j]
                if c >= v:
                    m_left -= 1
                    c = 0
                
            #print(left, right)
            #print("m_left", m_left)

            if m_left > 0:
                high = right - 1
            else:
                ans = max(ans, sum(a[left:right + 1]))
                low = right + 1
            #print(low, high)
    #print(partiton_idxs)
    sys.stdout.write(str(ans) + '\n')

for _ in range(int(input())):
    sta()