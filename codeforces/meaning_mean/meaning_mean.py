def sta():
    n, x = list(map(int, input().split(' ')))
    arr = list(map(int, input().split(' ')))

    s = set()
    d = {}
    for i in arr:
        if arr[i] % x not in d:
            d[arr[i] % x] = 0
        d[arr[i] % x] += 1
    
    m_key = 0
    m_val = 1000000
    for k in d:
        if d[k] < m_val:
            m_val = d[k]
        m_key = k
    
    return x * m_val + m_key + 1

for _ in range(int(input())):
    print(sta())
