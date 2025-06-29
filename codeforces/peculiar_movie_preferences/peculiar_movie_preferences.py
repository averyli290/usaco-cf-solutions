import sys

def sta():
    n = int(input())
    seen = set()
    seen3 = set()
    done = False
    for i in range(n):
        x = input()
        seen.add(x)
        if len(x) == 3:
            seen3.add(x[:2])
        if x[1:][::-1] in seen and not done:
            sys.stdout.write('YES\n')
            done = True
        if x[::-1] in seen and not done:
            sys.stdout.write('YES\n')
            done = True
        if x[::-1] in seen3 and not done:
            sys.stdout.write('YES\n')
            done = True
    if not done:
        sys.stdout.write('NO\n')


for _ in range(int(input())):
    sta()
