'''
Avery Li
XX/XX/XXXX
https://codeforces.com/contest/2064/problem/B
'''

from collections import defaultdict

def sta():
    # Given an array and index i, the if a[i] != a[i + 1]
    # we can exclude a[i + 1] and it would be an optimal choice for a[:i+2]
    # 
    # removing any number will no increase the score
    # find the longest contiguous subarray with elements of frequency 1

    n = int(input())
    l = list(map(int, input().split()))


    freq = defaultdict(int)
    for i in l:
        freq[i] += 1


    ans = [0 for i in range(n)]
    ans[0] = 1 if freq[l[0]] == 1 else 0
    for i in range(1, n): 
        if freq[l[i]] == 1:
            ans[i] = ans[i - 1] + 1
    
    m = max(ans)

    if m == 0:
        return 0

    #print(ans)

    for i in range(n):
        if ans[i] == m:
            return f"%d %d"%(i-m + 2, i + 1)

        

for _ in range(int(input())):
    print(sta())