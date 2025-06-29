
def sta():
    n = int(input())
    p_i = list(map(int, input().split(' ')))
    
    for i in range(n):
        p_i[i] -= 1

    b_f_r = [set() for i in range(n)]
    for i in range(n):
        b_f_r[p_i[i]].add(i)

    longer_than_1 = False
    for i in range(n):
        for j in list(b_f_r[i]):
            if i in b_f_r[j]:
                return 2
        if len(b_f_r) >= 2:
            longer_than_1 = True
    
    if longer_than_1:
        return 3
    return 4
            

for _ in range(int(input())):
    print(sta())