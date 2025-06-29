s = input().strip()

dp = [[0 for j in range(101)] for i in range(len(s) + 1)]
m = 10 ** 9 + 7

# dp[i][j] = string up to and including character i, how many ways to get value j
# dp[i][j] = dp[i - 1][j - v] for a given v

for i in range(0, len(s)):
    v = ord(s[i]) - ord('a') + 1
    j = 0
    dp[i][0] = 1
    while v + j <= 100:
        dp[i + 1][v + j] += dp[i][j]
        dp[i + 1][j] %= m
        j += 1
    j = 0
    while j <= 100:
        dp[i + 1][j] += dp[i][j]
        dp[i + 1][j] %= m
        j += 1


print(dp[len(s)][100] % m)