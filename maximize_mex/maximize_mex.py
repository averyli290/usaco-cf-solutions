
def sta():
    n, x = list(map(int, input().split(' ')))
    arr = list(map(int, input().split(' ')))

    s = set()
    d = {}

    '''
    for i in range(n):
        if arr[i] % x not in d:
            d[arr[i] % x] = 0
        d[arr[i] % x] += 1
    m_key = 0
    m_val = 1000000
    for k in d:
        if d[k] < m_val:
            m_val = d[k]
        m_key = k
    
    return x * m_val + m_key
    '''
    for i in range(n):
        if arr[i] not in d:
            d[arr[i]] = 0
        d[arr[i]] += 1

    i = 0
    while True:
        if i not in d or d[i] == 0:
            return i
        if i + x not in d:
            d[i + x] = 0
        d[i + x] += d[i] - 1
        i += 1
    
    

for _ in range(int(input())):
    print(sta())