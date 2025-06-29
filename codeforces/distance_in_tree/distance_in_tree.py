'''
Avery Li
4/21/2025
Problem link:
'''

'''
5 2
1 2
2 3
3 4
2 5

1-2-3-4
  |
  5
'''

import sys

def get_subtree_size(tree):
    subtree_size = (len(tree) + 1) * [0]
    visited = (len(tree) + 1) * [0]
    
    def get_subtree_size_rec(u, p):
        visited[u] = 1
        subtree_size[u] = 1
        for n in tree[u]:
            if n != p:
                get_subtree_size_rec(n, u)
                subtree_size[u] += subtree_size[n]
    
    get_subtree_size_rec(1, -1)
    return subtree_size 

def get_centroid(tree, subtree_size, tree_size, u, parent = -1):
    for v in tree[u]:
        if v != parent:
            if subtree_size[v] * 2 > tree_size:
                return get_centroid(tree, subtree_size, tree_size, v, u)

    return u

def centroid_decomp(tree, u, parent = -1, visited=None):
    if visited is None:
        visited = (len(tree) + 1) * [0]

    centroid = get_centroid(tree, get_subtree_size(tree), len(tree), u)
    visited[centroid] = 1

    for v in tree[u]:
        if v != parent:
            centroid_decomp(tree, )
    

def sta():
    n, k = list(map(int, sys.stdin.readline().strip().split()))

    tree = {}
    for i in range(n - 1):
        a, b = list(map(int, sys.stdin.readline().strip().split()))
        if a not in tree:
            tree[a] = []
        if b not in tree:
            tree[b] = []
        tree[a].append(b)
        tree[b].append(a)
    
    print(tree)
    subtree_size = get_subtree_size(tree)
    print(subtree_size)
    print(get_centroid(tree, subtree_size, n, 1, -1))

sta()