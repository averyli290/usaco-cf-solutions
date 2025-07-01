n, k = list(map(int, input().strip().split()))
p = list(map(int, input().strip().split()))

include = []
exclude = []

for i in range(n):
    include.append(p[i])
    old_exclude = exclude[::]
    for j in include:
        if j % p[i] != 0:
            exclude.append(j * p[i])
    for j in old_exclude:
        if j % p[i] != 0:
            include.append(j * p[i])

total = 0
for i in range(len(include)):
    total += k // include[i]
for i in range(len(exclude)):
    total -= k // exclude[i]

# print(include)
# print(exclude)

print(total)