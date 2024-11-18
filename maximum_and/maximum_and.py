import sys
def sta():
    n = int(sys.stdin.readline().strip())
    arr = list(map(int, sys.stdin.readline().strip()))

    one_before = [False for i in range(n)]  # inclusive
    one_after = [False for i in range(n)]   # inclusive
    zero_before = [False for i in range(n)]  # inclusive
    zero_after = [False for i in range(n)]   # inclusive
    b0 = False
    b1 = False
    for i in range(n):
        if n[i] == 1:
            b1 = True
        else:
            b0 = True
        one_before[i] = b1
        zero_before[i] = b0
    b0 = False
    b1 = False
    for i in range(n - 1, -1, -1):
        if n[i] == 1:
            b1 = True
        else:
            b0 = True
        one_after[i] = b1
        zero_after[i] = b0
    
    for i in range(n):
        if zero_after[i] and zero_before[i + n]:
            

for _ in range(int(input())):
    sta()