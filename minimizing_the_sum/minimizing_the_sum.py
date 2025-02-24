def sta():
    #
    # dp[i][j] = minimized first i entries using j changes
    #

    n, k = list(map(int, input().split()))
    l = list(map(int, input().split()))

    dp = [[float('inf') for j in range(k + 1)] for i in range(n + 1)]
    dp[0][0] = 0

    for i in range(n):
        for j in range(k + 1):
            min_a = float('inf')
            d = 0
            # in a segment of d + 1 elements, all of them can be transformed
            # into the minimum among them using d operations
            while j + d <= k and i + d < n:
                min_a = min(min_a, l[i + d])
                dp[i + d + 1][j + d] = min(dp[i][j] + min_a * (d + 1), dp[i + d + 1][j + d])
                d += 1
    
    min_elt = float('inf')
    for i in range(k + 1):
        min_elt = min(min_elt, dp[n][i])
    return min_elt


    



for _ in range(int(input())):#

    print(sta())