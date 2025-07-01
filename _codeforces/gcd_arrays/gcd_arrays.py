import sys

def sta():
    l, r, k = map(int, input().split())
    count = (r - l) // 2
    if l % 2 == 1 or r % 2 == 1:
        count += 1
    
    #print(l, r, count)

    if l == r and r == 1:
        sys.stdout.write('NO\n')
        return

    if l == r:
        sys.stdout.write('YES\n')
        return

    
    if count > k:
        sys.stdout.write('NO\n')
        return
    sys.stdout.write('YES\n')
        

for _ in range(int(input())):
    sta()
