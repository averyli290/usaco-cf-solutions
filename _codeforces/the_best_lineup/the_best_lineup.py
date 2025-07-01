def compare(a, b):
    return a > b

def sta():
    N = int(input())
    a = list(input().split())

    s = sorted(a)[::-1]
    

    b_free = [a[-1]]
    b_used = [a[-1]]
    used_chop = 0
    b = [a[-1]]
    # take when possible, swap when possible.
    # take if makes it better, swap if makes it better
    # take the best choice between take and swap
    # skip if neither makes it better
    # greedy
    for i in range(N - 2, -1, -1):
        no_change = ''.join(b)
        b.insert(0, a[i])
        taken = ''.join(b)
        b[0], b[1] = b[1], b[0]
        swapped = ''.join(b)

        if taken >= no_change and taken >= swapped:
            b[0], b[1] = b[1], b[0]
            used_chop += 1
        elif swapped > taken and swapped > no_change:
            #print("used_chop", used_chop)
            #print("before b", b)
            b = b[:used_chop+2]
            #print("after b", b)
            used_chop = 0
        else:
            b.pop(1)
        #print(b, used_chop)

        # if a[i - 1] >= b_free[0]:
        #     #print("greater", a[i - 1], b_free[0])
        #     b_free.insert(0, a[i - 1])
        # if a[i - 1] >= b_used[0]:
        #     used_chop += 1
        #     b_used.insert(0, a[i - 1])
        # elif len(b_used) > 1 and a[i - 1] >= b_used[1]:
        #     #print("chopped", used_chop)
        #     b_used = b_used[:used_chop + 1]
        #     used_chop = 0
        #     b_used.insert(1, a[i - 1])
    
    return ' '.join(b)
    #res1 = ' '.join(b_free)
    #res2 = ' '.join(b_used)
    #if res1 > res2:
    #    return res1
    #return res2
    

    # i = 0
    # counter = 0
    # a_str = ''.join(a)
    # done = False
    # b_start = []
    # while i < N and not done:
    #     to_add = s[i]
    #     b_start.append(to_add)
    #     for j in range(len(to_add)):
    #         if a_str[counter] != to_add[j]:
    #             done = True 
    #             break
    #         counter += 1
    #     if not done:
    #         i += 1
    
    # #print()
    # #print(s)
    # #print(a)
    # #print("different starting at", i)
    # # the number that caused the difference, remove the last instance of it
    # print(s)
    # diff_cause = s[i]
    # a_mod = a
    # for j in range(N - 1, -1, -1):
    #     if a_mod[j] == diff_cause:
    #         a_mod.pop(j)
    #         break
    # a_mod = a_mod[i:]
    # #print("b start", b_start)
    # #print("a_mod", a_mod)

    # b = [a_mod[-1]]
    # for i in range(len(a_mod) - 1, 0, -1):
    #     if a_mod[i - 1] >= b[0]:
    #         #print("greater", a_mod[i - 1], b[0])
    #         b.insert(0, a_mod[i - 1])
    # #print("b", b)

    # # b = [a[-1]]
    # # for i in range(N - 1, 0, -1):
    # #     if a[i - 1] > b[0]:
    # #         print("greater", a[i - 1], b[0])
    # #         b.insert(0, a[i - 1])
    
    # b_start.extend(b)

    # return ' '.join(b_start)





for _ in range(int(input())):
    print(sta())