import sys

# class TreeNode:
#     def __init__(self):
#         self.value = None   # (low, high, 'T/L/R'),
#                             # low/high are inclusive
#                             # T = Tree, L = Left, R = Right
#         self.left = None
#         self.right = None
# 
# class IntervalTree:
#     def __init__(self, range_size):
#         self.root = TreeNode(0, range_size, 'L')
#     
#     def insert_range(self, low, high, type):
#         cur = self.root
#         while low < cur.value[0] or high > cur.value[1]:


def sta():
    n, q = list(map(int, sys.stdin.readline().strip().split()))
    p = list(map(int, sys.stdin.readline().strip().split()))
    s = sys.stdin.readline().strip()

    # have a way to store ranges (bubbling left and bubbling right)
    # have a way to query ranges

    left_ranges = []
    right_ranges = []
    start = 0
    for i in range(1, n):
        if s[i] != s[i - 1]:
            if s[i] == 'L':
                right_ranges.append((start, i - 1))
            else:
                left_ranges.append((start, i - 1))
            start = i
    if s[-1] == 'L':
        left_ranges.append((start, n-1))
    else:
        right_ranges.append((start, n-1))

    for i in range(q):
        query = sys.stdin.readline().strip()
        # Update ranges
        to_update_l = -1
        to_update_r = -1
        which_type = 'R'
        for j in range(len(left_ranges)):
            if left_ranges[j][0] <= query and left_ranges[j][1] >= query:
                to_update_l = j
                which_type = 'L'
                break

        if which_type == 'L':
            if left_ranges[to_update_l][0] == query and left_ranges[to_update_l][1] == query:
                left_ranges.pop(to_update_l)
            elif left_ranges[to_update_l][0] == query:
                left_ranges[to_update_l][0] += 1
            elif left_ranges[to_update_l][1] == query:
                left_ranges[to_update_l][1] -= 1
            else:
                left_ranges.insert(to_update_l + 1, (left_ranges[to_update_l][0], query - 1))
                left_ranges.insert(to_update_l + 2, (query + 1, left_ranges[to_update_l][1]))
                left_ranges.pop(to_update_l)
            
            for j in range(len(right_ranges) - 1):
                if right_ranges[]

        else:
            

for _ in range(int(input())):
    sta()