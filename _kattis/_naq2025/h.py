import sys
import heapq

t = 0

class Node:
    def __init__(self, position, weight, next):
        self.position = position
        self.weight = weight
        self.nodes = 1
        self.disabled = False
        self.next = next
    def __lt__(self, other):
        diff = (self.weight / self.nodes - other.weight / other.nodes)
        if diff != 0:
            return diff >= 0
        else:
            return self.position - other.position > 0 if t > 0 else self.position - other.position < 0

def sta():
    n = int(sys.stdin.readline().strip())
    l = []
    global t
    for i in range(n):
        a, b = list(map(int, sys.stdin.readline().strip().split()))
        l.append((a,b))
        t += a * b
    head = Node(-1, -1, None)
    cur = head
    heap = []
    if t == 0:
        return 0
    elif t > 0:
        for i in range(len(l)-1, -1, -1):
            cur.next = Node(l[i][0], l[i][1], None)
            cur = cur.next
            heapq.heappush(heap, cur)
    else:
        for i in range(len(l)):
            cur.next = Node(l[i][0], l[i][1], None)
            cur = cur.next
            heapq.heappush(heap, cur)
    
    total_distance = 0

    while t > 0:
        node = heapq.heappop(heap)
        if node.disabled:
            continue
        if node.next == None:
            total_distance += t * node.nodes / node.weight
            return total_distance
        elif node.next.position - node.position >= t / node.weight:
            total_distance += t * node.nodes / node.weight
        else:
            node.position = node.next.position
            node.weight += node.next.weight
            node.nodes += node.next.nodes
            node.next.disabled = True
            node.next = node.next.next
    
    return -1
        

print(sta())