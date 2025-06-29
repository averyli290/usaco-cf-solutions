'''
Avery Li
XX/XX/XXXX
Problem link:
'''

def sta():
    n = input()
    a = 0
    b = 0
    for i in range(len(n)):
        if n[i] != '0':
            a = i
            b = 0
        if n[i] == '0':
            b += 1
    c = 0
    for i in range(a):
        if n[i] != '0':
            c += 1
    #print(c, b)
    return c + b


for _ in range(int(input())):
    print(sta())