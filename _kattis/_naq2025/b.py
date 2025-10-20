import sys

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def sta():
    r, c, n = list(map(int, sys.stdin.readline().strip().split()))
    grid1 = [[-1 for i in range(c)] for j in range(r)]
    grid2 = [[-1 for i in range(c)] for j in range(r)]

    def in_range(x, y):
        if x >= 0 and x < r and y >= 0 and y < c:
            return True
        return False

    q = []
    for i in range(n):
        x, y = list(map(int, sys.stdin.readline().strip().split()))
        q.append((x-1, y-1, i+1))
    while q:
        new_q = set()
        for i in q:
            x, y, t = i
            if grid1[x][y] == -1:
                grid1[x][y] = t
            elif grid2[x][y] == -1:
                grid2[x][y] = t
            else:
                continue
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if in_range(nx, ny) and grid2[nx][ny] == -1 and grid1[nx][ny] != t:
                    new_q.add((nx, ny, t))
        q = sorted(list(new_q), key=lambda x:x[2])
    for i in range(r):
        print(' '.join([str(k) for k in grid1[i]]))
    for i in range(r):
        print(' '.join([str(k) for k in grid2[i]]))

# for _ in range(int(input())):
#     print(sta())
sta()