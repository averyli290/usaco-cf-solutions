
def sta():
    n = int(input())
    s = input()
    
    N = s.count('N')
    E = s.count('E')
    S = s.count('S')
    W = s.count('W')

    x_diff = max(W, E) - min(W, E)
    y_diff = max(N, S) - min(N, S)
    if x_diff % 2 != 0 or y_diff % 2 != 0:
        return "NO"

    ans = []
    N_count = 0
    S_count = 0
    NS_min = min(N, S)
    EW_min = min(N, S)
    for i in range(n):
        c = s[i]
        if c == 'N':
            if N_count < NS_min:
    
    return 1





for _ in range(int(input())):
    print(sta())

