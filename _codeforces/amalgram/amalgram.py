import sys
from collections import defaultdict
def sta():
    # Perimeter doesn't change from a full rectangle

    a = sys.stdin.readline().strip()
    b = sys.stdin.readline().strip()
    c = defaultdict(int)
    d = defaultdict(int)
    keys = set()
    for i in a:
        c[i] += 1
        keys.add(i)
    for i in b:
        d[i] += 1
        keys.add(i)
    s = []    
    for k in keys:
        s.append(k * max(d[k], c[k]))
    sys.stdout.write(''.join(s) + '\n')

sta()