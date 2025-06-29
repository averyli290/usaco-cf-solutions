import sys
def sta():
    n = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().strip()

    if s[0] == '1' or s[-1] == '1':
        sys.stdout.write('YES')
        return
    for i in range(n - 1):
        if s[i] == '1' and s[i + 1] == '1':
            sys.stdout.write('YES')
            return
    sys.stdout.write('NO')


for _ in range(int(input())):
    sta()
    sys.stdout.write('\n')