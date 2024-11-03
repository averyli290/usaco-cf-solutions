import sys
def sta():
    # the number of 0 subseq is 2^(num of zeroes) - 1
    # the number of at least 1 in subseq is (num of ones) * 2^(len of string - 1)
    # want to minimize | (2^(# of 0's) - 1) - ((# of 1's) * 2^(len of string - 1))|
    n = int(sys.stdin.readline().strip())


    k = 0       # number of 0's
    # cur step: 2^(k - 1) - (i - k)*2^(i - 1)
    # next step opt 1 (k++): 2^(k) - (i - k)*2^(i)
    # next step opt 2 (k): 2^(k - 1) - (i + 1 - k)*2^(i)
    # |2^k - (i-k)*2^i| <? |2^(k-1) - (i + 1 - k)*2^(i)|
    # (i-k)*2^i - 2^k >= 0 
    # (i + 1 - k)*2^(i) - 2^(k-1) >= 0,
    # (i-k)*2^i - 2^k <= (i + 1 - k)*2^(i) - 2^(k-1) except for when n=2
    # always choose to add just 0's after for n > 2
    # start with 0, 01, then add just 0's
    if n == 1:
        sys.stdout.write('0')
    if n >= 2:
        sys.stdout.write('01'+(n-2)*'0')
    sys.stdout.write('\n')
    

for _ in range(int(input())):
    sta()