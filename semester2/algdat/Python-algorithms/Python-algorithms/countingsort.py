# -*- coding: utf-8 -*-
#
# Author: Jen Liebehenschel (2016-2020), <liebehenschel at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the counting sort algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Sorts input sequence into a separate array
# -----------------------------------------------------------------------------
#

def countingsort(A,k):
    # create temporary array C for counting
    C=[0 for x in range(k+1)]
    print ("C:",C)

    # count number of elements = i in C[i]
    for j in range(len(A)):
        C[A[j]] = C[A[j]] + 1
    print ("C:",C)
    
    # calculate number of elements <= i in C[i]
    for i in range(1,len(C)):
        C[i] = C[i] + C[i-1]
    print ("C:",C)

    # create (empty) output array B
    B=[-1 for x in range(len(A))]

    # sort
    for j in range(len(A)-1,-1,-1):
        B[C[A[j]]-1] = A[j]
        C[A[j]] = C[A[j]] - 1
    print ("C:",C)
    
    return B

A1=[1,9,3]
A2=[0, 1, 2, 3, 4, 5, 6, 7, 8]
A3=A2[:]
A3.reverse()
A4=[1, 9, 0, 5, 6, 7, 8, 2, 4, 3, 1, 3, 5, 3, 6, 3, 8, 2, 0, 3]
A5=[2, 5, 3, 0, 2, 3, 0, 3]

A=[A1, A2, A3, A4, A5]
for l in A:
    print("Before sorting: ", l)
    print("After sorting: ", countingsort(l,max(l)))
    l.sort()
    print("List sorted:   ", l, "\n")
