# import sys

# def sta():
#     # n, k = list(map(int, sys.stdin.readline().strip().split()))
#     a = sys.stdin.readline().strip().split()
#     d = {}
#     for i in range(10):
#         d[i] = 10
#     for i in a:
#         d[int(i[-1])] -= 1
#         if d[int(i[-1])] == 0:
             


# # for _ in range(int(input())):
# #     print(sta())

# sta()

last = input().strip()[-1]

if last == '0':
    print(10)
else:
    print(last)