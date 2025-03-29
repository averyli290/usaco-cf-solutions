upper_bound = 50005000    
prime = [0 for i in range(upper_bound + 1)]
p = 2
while (p * p <= upper_bound):
    if prime[p]:
        for i in range(p * p, upper_bound+1, p):
            prime[i] = 0
    p += 1


def sta():
    n = int(input())

for _ in range(int(input())):
    print(sta())