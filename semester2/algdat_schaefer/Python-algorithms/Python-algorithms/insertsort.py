# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the insert sort algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Sorts input a
# -----------------------------------------------------------------------------
#

def insertsort(a):
    for j in range(1, len(a)):
        key = a[j]
        i = j-1
        while i >= 0 and a[i] > key:
            a[i+1] = a[i]
            i = i-1
        a[i+1] = key
    return a

def insertsort2(a):
    for j in range(1, len(a)):
        key = a[j]
        i = j-1
        while i >= 0 and a[i] > key:
            a[i+1] = a[i]
            a[i] = key
            i = i-1
    return a

def insertsort2alternative(a):
    for j in range(1, len(a)):
        key = a[j]
        i = j-1
        while i >= 0 and a[i] > key:
            a[i+1] = a[i]
            i = i-1
        a[i+1] = key
    return a

def insertsortrec(j, a):
    if j >= len(a):
        return a
    else:
        key = a[j]
        i = j-1
        while i >= 0 and a[i] > key:            
            a[i+1] = a[i]
            a[i] = key
            i = i-1      
        return insertsortrec(j+1, a)

def insertsortrecalternative(j, a):
    if j >= len(a):
        return a
    else:
        key = a[j]
        i = j-1
        while i >= 0 and a[i] > key:            
            a[i+1] = a[i]
            i = i-1      
        a[i+1] = key
        return insertsortrec(j+1, a)

lists = [[5,2,7,4,6,1,3], [1,2,3,4], [5,4,3,2,1], [8,9,0,6,4,7,1,3,2,5] ]
# note: list(l) is required as parameter instead of l,
# otherwise the functions except the first one obtain a sorted list as input
for l in lists:
    print("To be sorted:", l)
    print(insertsort(list(l)))
    print(insertsort2(list(l)))
    print(insertsort2alternative(list(l)))
    print(insertsortrec(1,list(l)))
    print(insertsortrecalternative(0,list(l)))
    print()

