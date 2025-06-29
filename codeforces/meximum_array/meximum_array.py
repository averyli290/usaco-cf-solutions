import sys

def sta():
    n = int(input())
    a = map(int, input().split())
    b = []

    # calculuate mex of all prefixes

    #
    # At each step, want the maximum possible value of the mex
    # binary search for the maximum value of the mex

    # calculate the mex every step of binary search
    #
    # how to update the mexes in constant time ?
    #
    # Keep the value of mex of the a[:-1], binary search to find the earliest instance of that value
    #

    def mex(a, i, j):
        s = set()
        for k in range(i, j):
            s.add(a[k])
        for k in range(1, j - i + 1):
            if k not in s:
                return k
        return j - i + 1

    i = 0
    while i < n:
        



for _ in range(int(input())):
    sta()
