t = int(input())
n = list(map(int, input().split()))
k = list(map(int, input().split()))


for i in range(len(n)):
    print(pow(2, k[i], 1000000007))