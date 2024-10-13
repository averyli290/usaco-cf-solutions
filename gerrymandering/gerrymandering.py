
def sta():
    '''
    n = int(input())
    s1 = [1 if i == 'A' else 0 for i in input()]
    s2 = [1 if i == 'A' else 0 for i in input()]
    arr = [s1, s2]
    v = [[0 for i in range(n)] for j in range(2)]
    #print(n)
    #print(arr)

    def rec(cur_pos, visited):
        best = 0 
        other_row = (cur_pos[0] + 1) % 2 
        if cur_pos[1] == n - 1:
            return 0
        if cur_pos[1] + 3 < n:
            new_visited = [[j for j in i] for i in visited]
            new_visited[cur_pos[0]][cur_pos[1]] = 1
            new_visited[cur_pos[0]][cur_pos[1] + 1] = 1
            new_visited[cur_pos[0]][cur_pos[1] + 2] = 1
            new_cur_pos = []
            if visited[other_row][cur_pos[1]]:
                if visited[other_row][cur_pos[1] + 1]:
                    new_cur_pos = [other_row, cur_pos[1] + 2]
                else:
                    new_cur_pos = [other_row, cur_pos[1] + 1]
            else:
                new_cur_pos = [other_row, cur_pos[1]]
            
            plus_one = 1 if arr[cur_pos[0]][cur_pos[1]] + arr[cur_pos[0]][cur_pos[1] + 1] + arr[cur_pos[0]][cur_pos[1] + 2] >= 2 else 0
            
            best = max(rec(new_cur_pos, new_visited), best + plus_one)

        if not visited[other_row][cur_pos[1]]:
            new_visited_0 = [[j for j in i] for i in visited]
            new_visited_0[cur_pos[0]][cur_pos[1]] = 1
            new_visited_0[other_row][cur_pos[1]] = 1
            new_visited_0[other_row][cur_pos[1] + 1] = 1
            plus_one_0 = 1 if arr[cur_pos[0]][cur_pos[1]] + arr[other_row][cur_pos[1]] + arr[other_row][cur_pos[1] + 1] >= 2 else 0
            best = max(rec([cur_pos[0], cur_pos[1] + 1], new_visited_0), best + plus_one_0)
            new_visited_1 = [[j for j in i] for i in visited]
            new_visited_1[cur_pos[0]][cur_pos[1]] = 1
            new_visited_1[other_row][cur_pos[1]] = 1
            new_visited_1[cur_pos[0]][cur_pos[1] + 1] = 1
            plus_one_1 = 1 if arr[cur_pos[0]][cur_pos[1]] + arr[other_row][cur_pos[1]] + arr[cur_pos[0]][cur_pos[1] + 1] >= 2 else 0
            best = max(rec([other_row, cur_pos[1] + 1], new_visited_1), best + plus_one_1)
        elif not visited[other_row][cur_pos[1] + 1]:
            new_visited_0 = [[j for j in i] for i in visited]
            new_visited_0[cur_pos[0]][cur_pos[1]] = 1
            #print("nv 0:",new_visited_0)
            #print(cur_pos[0] ,cur_pos[1] + 1)
            new_visited_0[cur_pos[0]][cur_pos[1] + 1] = 1
            new_visited_0[other_row][cur_pos[1] + 1] = 1
            plus_one_0 = 1 if arr[cur_pos[0]][cur_pos[1]] + arr[other_row][cur_pos[1] + 1] + arr[cur_pos[0]][cur_pos[1] + 1] >= 2 else 0
            best = max(rec([cur_pos[0], cur_pos[1] + 1], new_visited_0), best + plus_one_0)
        return best
        #if cur_pos[0] == 0: # on the top row
        #else: # on the bottom row

    return rec([0, 0], v)
    '''
    n = int(input())
    s1 = input()
    s2 = input()
    


for _ in range(int(input())):
    print(sta())