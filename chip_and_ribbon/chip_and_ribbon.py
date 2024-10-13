def sta():
    n = int(input())
    c = list(map(int, input().split(' ')))

    '''
    Iterate across c
    every time c decreases (height goes down) we can add teleports
    equal to the height difference from the last height and
    max between the previous minimum height (height starts going up)
    and the current height. Update the previous minimum height if needed
    
        . .
      . . .   . .
    . . . . . . .
    1 2 3 3 1 2 2

    counting the heights of mounds represented by numbers
    '''
    total = 0
    earlier_min = 1
    for i in range(1, len(c)):
        if c[i] < c[i - 1]:
            #print("prec", c[i - 1])
            #print("cur", c[i])
            #print("ee", earlier_min)
            total += c[i - 1] - max(earlier_min, c[i])
            earlier_min = min(earlier_min, c[i])
        #print("e", earlier_min)
    
    if c[n - 1] > earlier_min:
        total += c[n - 1] - earlier_min
    return total

for _ in range(int(input())):
    print(sta())