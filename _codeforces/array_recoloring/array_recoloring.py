'''
Avery Li
3/17/2025
Problem link: https://codeforces.com/contest/2075/problem/B
'''

def sta():
    n, k = list(map(int, input().strip().split()))
    l = list(map(int, input().strip().split()))
    new_l = [(i, l[i]) for i in range(n)]
    new_l = sorted(new_l, key=lambda x: x[1], reverse=True)
    taken = [0 for i in range(n)]
    ans = 0
    for i in range(k):
        ans += new_l[i][1]
        taken[new_l[i][0]] = 1
    #print(new_l)
    #print(taken)
    #print(n, k, n-k-1)
    
    for i in range(n - k - 1):
        m_val = float('inf')
        m_ind = -1
        for j in range(n):
            if ((j > 0 and l[j - 1] == 1) or (j < n - 1 and l[j + 1] == 1)):
                if taken[j] == 0 and l[j] < m_val:
                    m_val = l[j]
                    m_ind = j
        taken[m_ind] = 1
        print(i, taken)
    
    for i in range(n):
        if taken[i] == 0:
            ans += l[i]
            return ans
    
            

for _ in range(int(input())):
    print(sta())