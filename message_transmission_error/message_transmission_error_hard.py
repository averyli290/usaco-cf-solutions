s = input()

n = len(s)

i = 1
while i < (n + 1) // 2:
    s2 = s[i:]
    j = 0
    while j < n - i and s2[j] == s[j]:
        j += 1
    if j == n - i:
        print("YES")
        print(s2)
        break
    i += 1

if i == (n + 1) // 2:
    print("NO")