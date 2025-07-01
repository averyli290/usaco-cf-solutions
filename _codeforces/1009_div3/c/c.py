def sta():
    s =int(input()) 
    x = bin(s)[2:]
    
    res = ['1']
    for i in range(1, len(x)):
        if x[i] == '1':
            res.append('0')
        else:
            res.append('1')
    y = ''.join(res)
    a = int(x, base=2)
    b = int(y, base=2)

    l = sorted([a, b, a ^ b])
    if l[0] + l[1] > l[2]:
        return min(b, a ^ b)
    else:
        return -1
    
for _ in range(int(input())):
    print(sta())