def sta():
    s_inp = input()

    total = 0
    block_length = 0
    shift_length = 0

    if '1' not in s_inp:
        return 0
    s = s_inp[s_inp.index('1'):] 

    to_shift = False
    #print("s:", s)
    for i in range(len(s)):
        #print(i, block_length, shift_length, total)
        if s[i] == '1':
            if to_shift:
                total += (shift_length) * (block_length + 1) 
                #print("Added")
                shift_length = 0 
                to_shift = False
            block_length += 1
        else:
            to_shift = True 
            shift_length += 1
    
    #print(block_length, shift_length, total)
    total += (block_length + 1) * shift_length 
    
    return total




for _ in range(int(input())):
    print(sta())