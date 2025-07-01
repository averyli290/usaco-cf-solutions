s = input()

n = len(s)

i = 0
j = 1
while i < (n + 1) // 2:
    if s[i] == s[j]:
        i += 1
        j += 1
    else:


if i == (n + 1) // 2:
    print("NO")