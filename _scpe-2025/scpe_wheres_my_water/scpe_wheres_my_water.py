n, p = list(map(int, input().strip().split()))

edges = [[] for i in range(p)]

resid = [[0 for i in range(n)] for j in range(n)]

for i in range(p):
    a, b, c = list(map(int, input().strip().split()))
    edges[a].append((b, c))
    resid[a][b] = c


