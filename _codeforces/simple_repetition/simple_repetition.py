'''
Avery Li
XX/XX/XXXX
Problem link:
'''

def is_prime(n):
    if n == 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    for i in range(5, int(n ** (1/2)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
            
    return True

def sta():
    x, k = list(map(int, input().strip().split()))
    if k == 1:
        if is_prime(x):
            return "YES"
        return "NO"
    if x >= 10:
        return "NO"
    if not is_prime(int(str(x) * k)):
        return "NO"
    return "YES"

for _ in range(int(input())):
    print(sta())