import sys
    
def dfs(s, max):
    # print(s, max)
    if len(s) == 0:
        return True, set()
    if len(s) == 1:
        return False, None
    last_char = s[-1]
    if int(last_char) >= max:
        return False, None
    
    ans = {last_char}
    if len(s) >= 2 and (ret := dfs(s[:-2], int(last_char)))[0]:
        ans.update(ret[1])
        return True, ans
    elif len(s) >= 3 and (ret := dfs(s[:-3], int(last_char)))[0]:
        ans.update(ret[1])
        return True, ans
    return False, None
        
    
    
def f():
    n, m = [i for i in sys.stdin.readline().split()]
    
    if n == m:
        sys.stdout.write(str(1))
        return
    
    if not (ret := dfs(m, 10))[0]:
        sys.stdout.write('Does not exist')
        return
    # print(ret)
    
    m_chars = ret[1]
    # print(m_chars)
    traversed = {n}
    
    for i in range(1, 101):
        if n == m:
            sys.stdout.write(str(i))
            return
        
        if len(set(n) - m_chars) > 0:
            sys.stdout.write('Does not appear')
            return
    
        freq = {}
        for c in n:
            if c in freq:
                freq[c] += 1
            else:
                freq[c] = 1
        new_n = ''
        for i in range(0, 10):
            if str(i) in freq:
                new_n += str(freq[str(i)]) + str(i)
        if new_n in traversed:
            sys.stdout.write('Does not appear')
            return
        n = new_n
    sys.stdout.write("I'm bored")
    return
    
f()
