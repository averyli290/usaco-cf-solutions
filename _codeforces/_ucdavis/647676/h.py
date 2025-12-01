import sys

def sta():
    n, m = list(map(int, sys.stdin.readline().strip().split()))

    neighbors = [[] for i in range(n)]
    for i in range(m):
        x, y = list(map(int, sys.stdin.readline().strip().split()))
        neighbors[x-1].append(y-1)
    
    a, b = list(map(int, sys.stdin.readline().strip().split()))
    a, b = a-1, b-1

    a_possible = set()

    # dfs from a
    q = set([a])
    while q:
        n = q.pop()
        if n not in a_possible:
            a_possible.add(n)
            for i in neighbors[n]:
                if i not in a_possible:
                    q.add(i)
    
    traversed = set()
    q = set([b])
    while q:
        n = q.pop()
        traversed.add(n)
        if n in a_possible:
            print(f'yes\n{n+1}')
            return
        for i in neighbors[n]:
            q.add(i)
    
    print('no')

sta()