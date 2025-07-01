

g = {}

g = {
    0: [2],
    1: [3],
    2: [],
    3: [],
}

visited = [0 for i in g]
ans = []

def dfs(v):
    global visited
    global ans
    visited[v] = True
    for n in g[v]:
        if not visited[v]:
            dfs(n)
    ans.append(v)

def topo():
    global visited
    global ans
    visited = [0 for i in g]
    for v in g:
        if not visited[v]:
            dfs(v)
    print(ans)
    ans = ans[::-1]

topo()
print(ans)