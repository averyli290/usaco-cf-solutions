import sys

'''
1 2 3 4 5
6 7 8 9 10

if odd num of odd: can add 1 to even num or 1 to odd
add 1 to even keep
add 1 to odd makes op invalid

using even op keeps ops validity state
using odd op flips validity of ops


'''

def sta():
    n = int(input())
    a = list(map(int, sys.stdin.readline().strip().split()))
    b = list(map(int, sys.stdin.readline().strip().split()))

    diff_parity = 0
    num_odd = 0
    num_even = 0
    for i in range(n):
        if a[i] > b[i]:
            sys.stdout.write('NO\n')
            return
        if a[i] % 2 != b[i] % 2:
            diff_parity += 1
            if diff_parity > 1:
                sys.stdout.write('NO\n')
                return
        num_odd += a[i] % 2 == 1
        num_even += a[i] % 2 == 0
    
    if a == b:
        sys.stdout.write('YES\n')
        return
    
    if diff_parity == 0 and num_even % 2 == 1:
        sys.stdout.write('NO\n')
        return
    if diff_parity == 1 and num_odd % 2 == 0:
        sys.stdout.write('NO\n')
        return
    sys.stdout.write('YES\n')

for _ in range(int(input())):
    sta()
