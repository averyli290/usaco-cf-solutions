import sys

def sta():
    r, g, b = list(map(int, sys.stdin.readline().strip().split()))
    cr, cg, cb = list(map(int, sys.stdin.readline().strip().split()))
    arg, agb = list(map(int, sys.stdin.readline().strip().split()))

    nr, ng, nb = max(0, r - cr), max(0, g - cg), max(0, b - cb)

    if nr > arg or nb > agb or nr + ng + nb > arg + agb:
        return -1
    else:
        return nr + ng + nb

print(sta())