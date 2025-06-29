from collections import defaultdict
def sta():
    n = int(input())
    l = list(map(int, input().strip().split()))


    tables = defaultdict(int)
    cur_diag = 2 # tracks nearest table, near table(i,j), sum of i and j = cur_diag

    def output(tup):
        # returns coord for seating person at table
        people = tables[tup]
        if people == 0:
            return str(tup[0] * 3 + 1) + ' ' + str(tup[1] * 3 + 1)
        if people == 1:
            return str(tup[0] * 3 + 1) + ' ' + str(tup[1] * 3 + 2)
        if people == 2:
            return str(tup[0] * 3 + 2) + ' ' + str(tup[1] * 3 + 1)
        if people == 3:
            return str(tup[0] * 3 + 2) + ' ' + str(tup[1] * 3 + 2)
    
    def dist(tup):
        people = tables[tup]
        if people == 0:
            return tup[0] * 3 + tup[1] * 3 + 2
        if people == 1:
            return tup[0] * 3 + tup[1] * 3 + 3
        if people == 2:
            return tup[0] * 3 + tup[1] * 3 + 3
        if people == 3:
            return tup[0] * 3 + tup[1] * 3 + 6

    def free_x_coord(tup):
        people = tables[tup]
        if people == 0:
            return tup[0] * 3 + 1
        if people == 1:
            return tup[0] * 3 + 1
        if people == 2:
            return tup[0] * 3 + 2
        if people == 3:
            return tup[0] * 3 + 2

    # t = (1, 1)
    # tables[t] = 1
    # print(dist(t))
    # print(free_x_coord(t))
    # print()


    for i in range(n):
        if l[i] == 0:
            j = 0
            done = False
            while not done:
                k = 0
                while k <= j and not done:
                    tup = (k, j - k)
                    if tables[tup] == 0:
                        print(output(tup))
                        tables[tup] += 1
                        done = True
                        break
                    k += 1
                j += 1
        else:
            upper = 0
            while tables[(0, upper)] > 0:
                upper += 1
            done = False
            m_dist = float('inf')
            to_use = (float('inf'), float('inf'))
            j = 0
            while j <= upper:
                k = 0
                while k <= j:
                    tup = (k, j - k)
                    #print("tup", tup, tables[tup], dist(tup))
                    if tables[tup] < 4 and dist(tup) <= m_dist:
                        if free_x_coord(tup) <= free_x_coord(to_use):
                            m_dist = dist(tup)
                            to_use = tup
                            #print("new", tup)
                    k += 1
                j += 1
            print(output(to_use))
            tables[to_use] += 1

    

for _ in range(int(input())):
    sta()