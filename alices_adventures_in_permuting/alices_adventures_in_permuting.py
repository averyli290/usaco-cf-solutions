import sys

def sta():
    n, b, c = list(map(int, sys.stdin.readline().strip().split(' ')))

    if b == 0 and c < n-2:
        sys.stdout.write('-1\n')
        return

    num_less_than_n = 1 if b < n and c < n else 0

    if b != 0:
        num_less_than_n = max(0, (n - c) // b + ((n - c) % b > 0))

    ans = n - num_less_than_n 
    sys.stdout.write(str(ans) + '\n')
    
    

for _ in range(int(input())):
    sta()