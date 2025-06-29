def sta():
    n, c, d = list(map(int, input().split(' ')))
    arr = list(map(int, input().split(' ')))
    
    arr = sorted(arr)[::-1]
    pre = [0 for i in range(max(d, n))]
    cur = 0
    for i in range(max(d, n)):
        if i < n:
            cur += arr[i]
        pre[i] = cur
    
    if pre[d - 1] >= c:
        return "Infinity"
    

    for i in range(d,1,-1):
        #print(d % (i + 1))
        #print("r, m" , d // i, d % i)
        total = pre[i-1] * (d // i)
        #print(pre[i-1] * (d // i) , pre[d % i - 1])
        if d % i > 0:
            total += pre[d % i - 1]
        if total >= c:
            return i - 1
    '''
    low = 0
    high = d - 1
    ans = -1
    while low < high:
        mid = (low + high) // 2
        total = pre[mid] * (d // (mid + 1)) + pre[d % (mid + 1)]
        print("pre[mid]", pre[mid])
        print("repeated", d // (mid + 1))
        print("l,m,h", low, mid, high)
        if total >= c:
            print("total,c", total, c)
            ans = mid + 1
            ans = max(ans, mid + 1)
            high = mid
        else:
            low = mid + 1
    if ans != -1:
        return ans
    '''
    if d * pre[0] >= c:
        return 0
    return "Impossible"

for _ in range(int(input())):
    print(sta())