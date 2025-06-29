import sys
def sta():
    # Perimeter doesn't change from a full rectangle

    n = int(sys.stdin.readline().strip())
    H, W = 0, 0
    for i in range(n):
        w, h = list(map(int, sys.stdin.readline().strip().split()))
        H = max(H, h)
        W = max(W, w)

    sys.stdout.write(str(2 * (H + W)) + '\n')

for _ in range(int(input())):
    sta()