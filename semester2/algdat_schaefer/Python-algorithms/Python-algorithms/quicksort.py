# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the quick sort algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Sorts input sequence a (in place)
# -----------------------------------------------------------------------------
#
import random


qcount = 0
def quicksort(a, p, r):
    global qcount
    qcount += 1
    if p < r:
        q = partition(a, p, r)
        quicksort(a, p, q-1)
        quicksort(a, q+1, r)
    return a

def partition(a, p, r):
    x = a[r] # pivot
    i = p-1
    for j in range(p, r):
        if a[j] <= x:
            i = i+1
            a[i], a[j] = a[j], a[i]
    a[i+1], a[r] = a[r], a[i+1]
    return i+1

def qsort(a):
    return quicksort(a, 0, len(a)-1)
# -----------------------------------------------------------------------------
# A more functional version
# -----------------------------------------------------------------------------


############################################ <- use this
def qs(a):
    if not a:
        return []
    else:
        pivot = min(a)
        less = [x for x in a[:-1] if x <=  pivot]
        more = [x for x in a[:-1] if x > pivot]
        print(f"more: {more if more else "/"}, less: {less if less else "/"}")
        return qs(more) + [pivot] + qs(less)

# -----------------------------------------------------------------------------
# Another more functional version
# -----------------------------------------------------------------------------

def qsf(a):
    if not a: # if not a is empty list
        return []
    else:
        pivot = a[-1] # a[-1] = a[n-1] (right most element)
        less = [x for x in a[:-1] if x <= pivot] # a[:-1] = a[0, ..., n-2], i.e. exclude pivot 
        more = [x for x in a[:-1] if x > pivot]
        return qsf(less) + [pivot] + qsf(more) 

b = [1,8,3,6,5,4,7,2,9]
print(qsort([1, 2, 3, 4, 5, 6, 7, 8, 9]))
print(qcount)

qcount = 0
print(qsort([1, 2, 3, 4, 5]))
print(qcount)

qcount = 0
print(qsort([4, 3, 2, 1]))
print(qcount)

qcount = 0
print(qsort([1, 2, 3]))
print(qcount)

for i in range(10):
    qcount = 0
    print(qsort([random.randint(1, 9) for i in range(10)]))
    print(qcount)

