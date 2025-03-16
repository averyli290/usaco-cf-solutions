import sys

def sta():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    #print(n, k, a, b)
    temp = [0] * n
    for i in range(n):
        temp[i] = (a[i], b[i])
    temp = sorted(temp, key=lambda x: x[0])
    for i in range(n):
        if k < temp[i][0]:
            sys.stdout.write(str(k) + '\n')
            return
        k += temp[i][1]
    sys.stdout.write(str(k) + '\n')
        

for _ in range(int(input())):
    sta()
