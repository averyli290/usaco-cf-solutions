def sta():
    n, k = list(map(int, input().split(' ')))
    l = list(map(int, input().split(' ')))

    m_p = [[0 for i in range(n)] for j in range(k+1)]
    m_p[0] = [i for i in l]

    for i in range(1, k + 1):
        for j in range(n):
            if j + 1 < n and j - 1 >= 0:
                m_p[i][j] = min(m_p[i - 1][j], min(m_p[i - 1][j - 1], m_p[i - 1][j + 1]))
            elif j + 1 < n:
                m_p[i][j] = min(m_p[i - 1][j],  m_p[i - 1][j + 1])
            elif j - 1 >= 0:
                m_p[i][j] = min(m_p[i - 1][j],  m_p[i - 1][j - 1])
            else:
                m_p[i][j] = m_p[i - 1][j]
    
    for i in m_p:
        print(i)
    

for _ in range(int(input())):
    print(sta())