from collections import defaultdict

def sta():
    N = int(input())
    prefs = list(map(int, input().split()))
    children = {}
    for i in range(N + 1):
        children[i] = set()

    parents = defaultdict(set)
    is_prefix = [0 for i in range(N+1)]
    for i in range(1, N + 1):
        is_prefix[prefs[i - 1]] = 1
        children[prefs[i - 1]].add(i)
        parents[i] = prefs[i - 1]
    
    is_prefix[0] = 1
    M = N + 1 - sum(is_prefix) # not prefix
    #print(M)
    for i in range(M):
        num = int(input())
        length = 0
        found_branch = False
        if num == 0:
            print(0)
        else:
            while num != 0:
                #print(num, children)
                prev = num
                num = parents[num]
                if not found_branch and len(children[num]) > 1:
                    found_branch = True
                #print("children len", len(children[prev]))
                if len(children[prev]) == 0:
                    children[num].remove(prev)
                if found_branch:
                    length += 1
            print(length)
    

sta()