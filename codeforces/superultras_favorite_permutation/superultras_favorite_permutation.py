import sys

def sta():
    n = int(sys.stdin.readline().strip())
    if n < 5:
        sys.stdout.write('-1' + '\n')
        return
    if n == 5:
        sys.stdout.write('1 3 5 4 2' + '\n')
        return
    arr = [0 for i in range(n)]
    count = 0
    last = 0
    for i in range(1, n + 1, 2):
        arr[count] = i
        last = i
        count += 1
    if (last + 2) % 3 == 0:
        arr[count] = 2
        arr[count + 1] = 4
        arr[count + 2] = 6
    elif (last + 4) % 3 == 0:
        arr[count] = 4
        arr[count + 1] = 2
        arr[count + 2] = 6
    else:
        arr[count] = 6
        arr[count + 1] = 4
        arr[count + 2] = 2
    count += 3
    for i in range(8, n + 1, 2):
        arr[count] = i
        count += 1
    sys.stdout.write(' '.join([str(i) for i in arr]) + '\n')



for _ in range(int(input())):
    sta()