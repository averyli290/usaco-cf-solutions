from itertools import product

LIMIT = 200

tests = []

# n = 1
tests.append((1, [1]))

n = 2
while len(tests) < LIMIT:
    for tup in product(range(1, n + 1), repeat=n):
        tests.append((n, list(tup)))
        if len(tests) == LIMIT:
            break
    n += 1

print(LIMIT)
for n, arr in tests:
    print(f"{n} 0")
    print(*arr)