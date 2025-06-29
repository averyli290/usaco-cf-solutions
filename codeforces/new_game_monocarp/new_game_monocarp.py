def sta():
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))

    # sliding window
    j = -1
    ans = 0
    for i in range(0, n):
        while j - i > k and a[j + 1] <= a[j] + 1:
            j += 1
        ans = max(ans, i - j + 1)
    return ans
        

for _ in range(int(input())):
    print(sta())