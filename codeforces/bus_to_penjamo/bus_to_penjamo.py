def sta():
    n, r  = list(map(int, input().split(' ')))
    a = list(map(int, input().split(' ')))
    
    total = 0
    rows_used = 0
    people_left = 0
    for i in range(n):
        total += a[i] // 2 * 2
        rows_used += a[i] // 2
        a[i] %= 2
    
    s = sum(a)
    total += min(s, (r - rows_used) * 2 - s)

    print(total)
    


for _ in range(int(input())):
    sta()