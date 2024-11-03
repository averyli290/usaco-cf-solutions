
def sta():
    n = int(input())
    s1 = input()
    s2 = input()

    arr = [[1 if i == 'A' else 0 for i in s1], [1 if i == 'A' else 0 for i in s2]]

    vote = lambda x, y, z: x + y + z >= 2
    dp = [[0 for i in range(n + 1)] for i in range(3)]
    for i in range(0, n, 3):
        if i >= 1:
            # . . . . o
            # . . . o o
            dp[0][i] = max(dp[0][i], dp[1][i - 1] + vote(arr[0][i], arr[1][i - 1], arr[1][i]))
            # . . . o o
            # . . . . o
            dp[0][i] = max(dp[0][i], dp[2][i - 1] + vote(arr[0][i], arr[0][i - 1], arr[1][i]))
        dp[0][i + 3] = max(dp[0][i + 3], dp[0][i] + vote(arr[0][i + 1], arr[0][i + 2], arr[0][i + 3]))
        dp[0][i + 3] = max(dp[0][i + 3], dp[0][i] + vote(arr[1][i + 1], arr[1][i + 2], arr[1][i + 3]))

        # . . .
        # . . 
        dp[1][i + 3] = max(dp[1][i + 3], dp[1][i] + vote(arr[0][i + 1], arr[0][i + 2], arr[0][i + 3]))
        dp[1][i + 3] = max(dp[1][i + 3], dp[0][i] + vote(arr[1][i + 1], arr[1][i + 2], arr[1][i + 3]))




for _ in range(int(input())):
    print(sta())