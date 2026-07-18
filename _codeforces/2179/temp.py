
n = 15
for i in range(1, n + 1):
    val = 1
    temp = i
    while temp % 2 == 0:
        val *= 2
        temp //= 2
    # print(i * val, end=' ')
    print(val, end=' ')
print()