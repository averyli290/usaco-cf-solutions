import sys

def sta():
    n = int(sys.stdin.readline().strip())
    days = []
    for i in range(n):
        s = sys.stdin.readline().strip()
        if 'rest' in s:
            days.append('rest')
        elif 'leg' in s:
            days.append('leg')
        else:
            days.append('arm')
    
    for i in range(0, 31):
        if i % 7 == 0:
            sys.stdout.write(str(i // 7 + 1) + ' ')
        day = days[i % n]
        if day == 'rest':
            sys.stdout.write('\U0001F60E') 
        elif day == 'leg':
            sys.stdout.write('\U0001F9B5')
        else:
            sys.stdout.write('\U0001F4AA')  
        if i % 7 == 6:
            sys.stdout.write('\n')
    sys.stdout.write('\n')

sta()