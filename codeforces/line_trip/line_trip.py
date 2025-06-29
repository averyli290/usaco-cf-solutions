
def sta():
    n, x = list(map(int, input().split(' ')))
    stops = list(map(int, input().split(' ')))
    stops.insert(0, 0)
    stops.append(stops[-1] + (x - stops[-1]) * 2)
    m = 0
    for i in range(1, n + 2):
        m = max(stops[i] - stops[i - 1], m)
    return m

for _ in range(int(input())):
    print(sta())