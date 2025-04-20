def isprime(x):
    if x <= 1:
        return 0
    if x <= 3:
        return 1
    if x % 2 == 0 or x % 3 == 0:
        return 0
    for i in range(5, int(pow(x, 1/2)) + 1, 6):
        if (x % i == 0 or x % (i + 2) == 0):
            return 0
    return 1

def sta():
    n = int(input())

    x = -1
    counter = 0
    while x == -1:
        if isprime(n // 2 - counter):
            x = n // 2 - counter
        elif isprime(n // 2 + counter):
            x = n // 2 + counter
        counter += 1

    
    seq = [str(x)]
    for i in range(1, n):
        if x - i > 0:
            seq.append(str(x - i))
        if x + i <= n:
            seq.append(str(x + i))
    
    return ' '.join(seq)
    



for _ in range(int(input())):
    print(sta())