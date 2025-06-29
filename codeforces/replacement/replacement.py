import sys
def sta():
    # As long as there is at least 1 and at least one 0, there will
    # be a 01 or 10 to replace with a 1 or 0. This means no matter
    # which location we replace with r_i, only the number of 0's
    # and 1's determines whether we can continue this process.
    # In other words, only the count of 1's and the count of 0's
    # matters, as long as there is at least one of each.

    n = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().strip()
    r = sys.stdin.readline().strip()

    zero_count = s.count('0')
    one_count = s.count('1')
    for i in range(n - 1):
        if zero_count == 0 or one_count == 0:
            sys.stdout.write('NO\n')
            return
        zero_count -= 1
        one_count -= 1
        if r[i] == '1':
            one_count += 1
        else:
            zero_count += 1
    sys.stdout.write('YES\n')

for _ in range(int(input())):
    sta()