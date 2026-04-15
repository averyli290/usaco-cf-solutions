from collections import deque, defaultdict

def sta():
    a, b, c, d = map(int, input().split())

    steps = 0
    while c >= a and d >= b:
        if c == a and d == b:
            return steps
        #print(c, d)
        if c > d:
            dec = (c - a) // d 
            if dec == 0:
                return -1
            steps += dec
            c -= dec * d
        else:
            #d -= c
            dec = (d - b) // c
            if dec == 0:
                return -1
            steps += dec
            d -= dec * c
        #steps += 1
    #jprint(c, d)
    return -1
    
    # #dp = [[float('inf')] * (d + 1) for _ in range(c + 1)]
    # dp = {}
    
    # if a > c or b > d:
    #     return -1

    # dp[(a, b)] = 0

    # q = deque()
    # q.appendleft((a, b))
    # while len(q) > 0:
    #     cur_a, cur_b = q.pop()
    #     if cur_a + cur_b < c + 1:
    #         #dp[cur_a + cur_b][cur_b] = min(dp[cur_a][cur_b], dp[cur_a + cur_b][cur_b]) + 1
    #         if (cur_a + cur_b, cur_b) not in dp:
    #             dp[(cur_a + cur_b, cur_b)] = dp[(cur_a, cur_b)] + 1
    #         else:
    #             dp[(cur_a + cur_b, cur_b)] = min(dp[(cur_a,cur_b)], dp[(cur_a+cur_b, cur_b)]) + 1
    #         q.appendleft((cur_a + cur_b, cur_b))
    #     if cur_b + cur_a < d + 1:
    #         #dp[cur_a][cur_b + cur_a] = min(dp[cur_a][cur_b], dp[cur_a][cur_b + cur_a]) + 1
    #         if (cur_a, cur_a + cur_b) not in dp:
    #             dp[(cur_a, cur_a + cur_b)] = dp[(cur_a, cur_b)] + 1
    #         else:
    #             dp[(cur_a, cur_a + cur_b)] = min(dp[(cur_a,cur_b)], dp[(cur_a, cur_a + cur_b)]) + 1
    #         q.appendleft((cur_a, cur_b + cur_a))
    
    # # for i in dp:
    # #     print(i)
    
    # #if dp[c][d] < float('inf'):
    # #    return dp[c][d]
    # if (c,d) not in dp:
    #     return -1
    # if dp[(c,d)] < float('inf'):
    #     return dp[(c,d)]
    # return -1



for _ in range(int(input())):
    print(sta())