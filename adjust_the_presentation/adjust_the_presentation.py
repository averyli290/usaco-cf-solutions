def sta():
    n, m, q = list(map(int, input().split(' ')))
    order = list(map(int, input().split(' ')))
    slides = list(map(int, input().split(' ')))
    to_ret = []


    d = {}  # person, slides to present
    for i in range(1, n + 1):
        d[i] = set()
    for i in range(m):
        d[slides[i]].add(i)        # have to present at time i

    l = sorted(d.items(), key=lambda p: min(p[1], default=1000000000))

    works = True
    for i in range(len(l)):
        if len(l[i][1]) == 0:
            break
        if order[i] != l[i][0]:
            works = False
            break
    if works:
        to_ret.append("YA")
    else:
        to_ret.append("TIDAK")

    for i in range(q):
        slide_to_change, person = list(map(int, input().split(' ')))
        slide_to_change -= 1
        prev_person = slides[slide_to_change]
        slides[slide_to_change] = person
        d[person].add(slide_to_change)
        d[prev_person].remove(slide_to_change)
        l = sorted(d.items(), key=lambda p: min(p[1], default=1000000000))

        works = True
        for i in range(len(l)):
            if len(l[i][1]) == 0:
                break
            if order[i] != l[i][0]:
                works = False
                break
        if works:
            to_ret.append("YA")
        else:
            to_ret.append("TIDAK")
    return '\n'.join(to_ret)

        
    
for _ in range(int(input())):
    print(sta())