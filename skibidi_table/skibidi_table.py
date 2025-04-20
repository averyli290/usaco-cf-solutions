'''
Avery Li
XX/XX/XXXX
Problem link:
'''

import sys

def sta():
    n = int(input())
    q = int(input())

    for i in range(q):
        s = list(sys.stdin.readline().strip().split())
        if len(s) == 2:
            d = bin(int(s[1]) - 1)[2:]
            d = '0' * (2 * n - len(d)) + d
            x = ''
            y = ''

            for i in range(0, 2 * n, 2):
                if d[i:i+2] == '00':
                    x += '0'
                    y += '0' 
                elif d[i:i+2] == '01':
                    x += '1'
                    y += '1'
                elif d[i:i+2] == '10':
                    x += '0'
                    y += '1'
                else:
                    x += '1'
                    y += '0'
            print(str(int(y, 2) + 1) + ' ' + str(int(x, 2) + 1))
            
        else:
            a, b = bin(int(s[1]) - 1)[2:], bin(int(s[2]) - 1)[2:]
            a = '0' * (n - len(a)) + a
            b = '0' * (n - len(b)) + b
            c = ''
            for i in range(n):
                if a[i] == '0' and b[i] == '0':
                    c += '00'
                elif a[i] == '1' and b[i] == '1':
                    c += '01'
                elif a[i] == '1' and b[i] == '0':
                    c += '10'
                else:
                    c += '11'
            print(str(int(c, 2) + 1))
            

for _ in range(int(input())):
    sta()