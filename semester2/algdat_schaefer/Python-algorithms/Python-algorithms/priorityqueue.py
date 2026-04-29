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
# Min Priority Queue using heap
# -----------------------------------------------------------------------------
#
import sys
INF = sys.maxsize # TODO should do better
        
def parent(i):
    return (i-1)//2

def left(i):
    return 2*i+1 # lists start with 0!

def right(i):
    return 2*i+2 # lists start with 0!

def heapify(a, heapsize, i):
    l = left(i)
    r = right(i)
    if l < heapsize and a[l] < a[i]:
        minimum = l
    else:
        minimum = i
    if r < heapsize and a[r] < a[minimum]:
        minimum = r
    if minimum != i:
        a[i], a[minimum] = a[minimum], a[i]
        heapify(a, heapsize, minimum)

def build_heap(a):
    heap_size = len(a)
    for i in range(len(a)//2, 0, -1):
        heapify(a, heap_size, i-1)

def min_heap(a):
    return a[0]

def extract_min(a):
    if len(a) == 0:
        return None
    minimum = a[0]
    del a[0]
    build_heap(a)
    return minimum

def insert_heap(a, x):
    a.append(x)
    decrease_key_heap(a, len(a)-1, x)

def decrease_key_heap(a, i, k):
    if k > a[i]:
        raise Exception("new key bigger than current key")
    a[i] = k
    while i > 0 and a[parent(i)] > a[i]:
        a[parent(i)], a[i] = a[i], a[parent(i)]
        i = parent(i)

# Tests with intermediate output:
lists = [[8,1,3,16,9], [5,2,7,4,6,1,3], [1,2,3,4], 
   [5,4,3,2,1], [8,9,0,6,4,7,1,3,2,5] ]
for l in lists:
    print("To be sorted:", l)
    build_heap(l)
    print("After build_heap:", l)
    insert_heap(l, 7)
    print("After insert_heap(7):", l)
    print("min_heap:", min_heap(l))
    for i in range(len(l)):
        print(l)
        print("min_heap:", extract_min(l))
    print()
