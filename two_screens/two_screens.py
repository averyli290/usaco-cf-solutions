def sta():
    a = input()
    b = input()
    l = 0
    i = 0
    while i < min(len(a), len(b)) and b[i] == a[i]:
        i += 1
        l = i
    
    return len(a) + len(b) - l + (1 if l > 0 else 0)

for _ in range(int(input())):
    print(sta())