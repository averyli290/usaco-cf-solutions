def sta():
    n = int(input())
    a = list(map(int, input().split(' ')))

    '''
    Strategy:
    Making the largest and smallest numbers the same
    guarantees making all of the other numbers the same.

    We can merge everything that has a difference of 1

    We can reduce the difference between any two numbers to
    diff // 2

    with two numbers, make first one even

    1 4 -> 4 7, 2 3 -> 4 5, 2 2
    1 6 -> 4 9, 2 4 -> 4 6, 2 3 -> 4 5, 2 2
    1 6 -> 8 13, 4 6 -> 6 8, 3 4 -> 4 5, 2 2
    '''

    b = a[0]
    c = a[0]
    for i in a:
        b = min(i, b)
        c = max(i, c)

    counter = 0
    res = []
    while b != c:
        if b % 2 == 0:
            b += 2
            c += 2
            res.append('2')
        else:
            b += 1
            c += 1
            res.append('1')
        b //= 2
        c //= 2
        #print(b,c )
        counter += 1

    print(counter)
    if counter <= n and counter > 0:
        print(' '.join(res))

for _ in range(int(input())):
    sta()