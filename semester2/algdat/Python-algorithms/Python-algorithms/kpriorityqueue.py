# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
#
# -----------------------------------------------------------------------------
# Min Priority Queue using heap for keyed Objects which are
# represented as tuples [object, key]. Need to maintain handles.
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

a = [['a', 8], ['b', 1], ['c', 3], ['d', 16], ['e', 9]]
h = {}
print(a)
build_heap(a, h)
print(a)
insert_heap(a, h, ['g', 7])
print(a)
print(extract_min(a, h))
print(a)
