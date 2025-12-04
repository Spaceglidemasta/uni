# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# Illustrates the Dijkstra algorithm for shortest paths
# (see Cormen et al, Introduction to algorithms)
#
# -----------------------------------------------------------------------------
# Computes shortest path in a tree with the Dijkstra algorithm
# -----------------------------------------------------------------------------
#
import sys
INF = sys.maxsize # TODO should do better
        
def parent(i):
    return i//2

def left(i):
    return 2*i+1 # lists start with 0!

def right(i):
    return 2*i+2 # lists start with 0!

def heapify(a, h, heapsize, i):
    l = left(i)
    r = right(i)
    if l < heapsize and a[l][1] < a[i][1]:
        minimum = l
    else:
        minimum = i
    if r < heapsize and a[r][1] < a[minimum][1]:
        minimum = r
    if minimum != i:
        h[a[i][0]], h[a[minimum][0]] = minimum, i
        a[i], a[minimum] = a[minimum], a[i]
        heapify(a, h, heapsize, minimum)

def build_heap(a, h):
    for i in range(len(a)):
        h[a[i][0]] = i
    heap_size = len(a)
    for i in range(len(a)//2, 0, -1):
        heapify(a, h, heap_size, i-1)

def min_heap(a, h):
    return a[0]

def extract_min(a, h):
    if len(a) == 0:
        return None
    minimum = a[0]
    del h[a[0][0]]
    del a[0]
    build_heap(a, h)
    return minimum

def insert_heap(a, h, x):
    a.append([x[0], INF])
    h[x[0]] = len(a)-1
    decrease_key_heap(a, h, x)

def decrease_key_heap(a, h, x):
    i = h[x[0]]
    k = x[1]
    if k > a[i][1]:
        raise Exception("new key bigger than current key")
    a[i][1] = k
    while i > 0 and a[parent(i)][1] > a[i][1]:
        a[parent(i)], a[i] = a[i], a[parent(i)]
        h[a[i][0]] = i
        i = parent(i)
        
# the Dijkstra algorithm
def dijkstra(G, start, end=None):
    D = {} # distance
    P = {} # dictionary of predecessors
    for vertex in list(G.keys()):
        D[vertex] = INF
    D[start] = 0
    Q = []
    h = {}
    for vertex in list(G.keys()):
        if vertex == start:
             insert_heap(Q, h, [vertex, 0])
        else:
             insert_heap(Q, h, [vertex, INF])
    while len(Q) != 0:
        print(Q)
        print(D)
        u = extract_min(Q, h)
        for v in G[u[0]]: # relax
            uvLength = D[u[0]] + G[u[0]][v]
            if uvLength < D[v]: 
                D[v] = uvLength
                P[v] = u
                if v in h:
                    print("relaxing %s" % v)
                    decrease_key_heap(Q, h, [v, uvLength])
                else:
                    insert_heap(Q, h, [v, uvLength])
    return D, P

def shortestPath(G, start, end):
    D, P = dijkstra(G, start, end)
    Path = []
    while 1:
        Path.append(end)
        if end == start: break
        end = P[end][0]
    Path.reverse()
    return Path

# generates dot presentation from Graph
def print_graph(G):
    print("digraph states {\nsize=\"4,3\";\nrankdir=LR;\nnode [shape=circle];")
    for node in list(G.keys()):
        print("%s [label = \"%s\"];" % (node, node))
    for nodeFrom in list(G.keys()):
        for nodeTo in list(G[nodeFrom].keys()):
            print("%s -> %s [label = \"%s\"];" % (nodeFrom, nodeTo, G[nodeFrom][nodeTo]))
    print("}")
                   
# Graph from Cormen et al, p. 599
G = {'s':{'y': 5, 't': 10}, 'y': {'t': 3, 'z': 1, 'x': 9}, 't': {'y': 2, 'x': 1}, 
         'x': {'z': 4}, 'z': {'x': 6, 's':7} }
G2 = {'s':{'y': 6, 't': 12, 'x': 5}, 'y': {'t': 3, 'z': 18, 'x': 8},
          't': {'y': 3, 'x': 22}, 'x': {'z': 5, 't': 3}, 'z': {'x': 6, 's':7} }
#print_graph(G)
#print_graph(G2)

print(dijkstra(G2, 't'))
print(shortestPath(G2, 't', 'z'))
print(print_graph(G))
