
def sta():
    n, m = list(map(int, input().strip().split()))
    mat = [[i for i in input().strip()] for j in range(n)]
    
    for i in range(n):
        for j in range(m):
            if mat[i][j] == '1':
                # check all the way up
                bad = 0
                for k in range(i):
                    if mat[k][j] == '0':
                        bad += 1
                        break
                for k in range(j):
                    if mat[i][k] == '0':
                        bad += 1
                        break
                if bad == 2:
                    return "NO"
                #if ((i > 0 and mat[i - 1][j] == '0') and (j > 0 and mat[i][j - 1] == '0')):
                #    return "NO"
    return "YES"
                
                

# 50005000    

for _ in range(int(input())):
    print(sta())