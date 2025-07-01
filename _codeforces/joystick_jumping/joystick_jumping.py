import sys


def sta():
    n = int(input())
    h = list(map(int, sys.stdin.readline().strip().split()))

    cur_right = 0
    cur_left = 0
    for i in range(n - 1):
        if h[i + 1] > h[i]:
            cur_right += 1
    
    ans_list = [0] * n
    ans_list[0] = cur_right
    for i in range(n - 1):
        if h[i + 1] < h[i]:
            cur_left += 1
        if h[i + 1] > h[i]:
            cur_right -= 1
        ans_list[i + 1] = max(cur_right, cur_left)
    
    print(' '.join([str(i) for i in ans_list]))




for _ in range(int(input())):
    sta()
