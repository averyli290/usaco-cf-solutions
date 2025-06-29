import sys

def sta():
    n = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))


    ans = [0 for i in range(n)]
    for i in range(n):
        cur_max_index = i
        max_from_back_index = [0 for j in range(i + 1)]
        for j in range(i, -1, -1):
            if ans[j] > a[cur_max_index]:
                cur_max_index = j
            max_from_back_index[j] = cur_max_index
        

        cur_pow_count = 0
        cur_sum = 0
        #print(max_from_back_index)
        for j in range(i + 1):
            if max_from_back_index[j] == j:
                cur_sum += a[j] * pow(2, cur_pow_count)
                cur_pow_count = 0
            else:
                temp = a[j]
                while temp % 2 == 0:
                    temp //= 2
                    cur_pow_count += 1
                cur_sum += temp
                running_sum += temp
            cur_sum %= 1000000007
        ans[i] = cur_sum
    
    sys.stdout.write(' '.join([str(i) for i in ans]) + '\n')


for _ in range(int(input())):
    sta()