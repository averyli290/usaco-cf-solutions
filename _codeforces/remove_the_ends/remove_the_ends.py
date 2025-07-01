'''
Avery Li
XX/XX/XXXX
https://codeforces.com/contest/2064/problem/C
'''



# [1, -10, -3, -17, -20, 19, 20]

def sta():
    # can always take positive numbers at the start and negative numbers at the end
    # Observation: taking a negative a_i invalidates all positive a_i in the suffix starting with a_i,
    #              , 
    #              taking a positive a_i invalidates all negative a_i in the suffix starting with a_i
    #
    # for each i, coins[i] = amount of coins gained
    # by taking prefix up to and including i and suffix after i

    n = int(input())
    l = list(map(int, input().split()))

    total = 0
    i = 0
    while i < n and l[i] >= 0:
        total += l[i]
        i += 1
    j = n - 1
    while j >= 0 and l[j] <= 0:
        total += -l[j]
        j -= 1
    
    l = l[i:j+1]
    n = len(l)

    suffix_neg = [0 for _ in range(n + 1)]
    prefix_pos = [0 for _ in range(n + 1)]
    for i in range(0, n):
        #print(i, l[i], prefix_pos)
        prefix_pos[i + 1] = prefix_pos[i]
        if l[i] > 0: 
            prefix_pos[i + 1] += l[i]

    for i in range(n - 1, -1, -1):
        #print(i, l[i], suffix_neg)
        suffix_neg[i] = suffix_neg[i + 1]
        if l[i] < 0: 
            suffix_neg[i] += -l[i]
    
    mid_max = 0
    for i in range(n + 1):
        mid_max = max(mid_max, suffix_neg[i] + prefix_pos[i])

    #print(l)
    #print(prefix_pos)
    #print(suffix_neg)
    total += mid_max

    return total




for _ in range(int(input())):
    print(sta())