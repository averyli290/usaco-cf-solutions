import sys
def sta():
    n = int(sys.stdin.readline().strip())
    sys.stdout.write("Yes\n" if n >= 2 and n <= 12 else "No\n")

sta()