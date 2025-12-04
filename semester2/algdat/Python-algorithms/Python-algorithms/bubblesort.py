# -*- coding: utf-8 -*-
#
# Author: Jens Liebehenschel (2016-2020), <liebehenschel at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the bubble sort algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Sorts input a
# -----------------------------------------------------------------------------
#

def bubblesort1(a):
    for i in range(len(a)-1):
#        print ("Run " + str(i))
        for j in range(len(a)-1,i,-1):
#            print (i,j)
#            print (a)
            if a[j] < a[j-1]:
                a[j],a[j-1] = a[j-1],a[j] # swap elements
#        print (a)
    return a

def bubblesort2(a):
    swapped = True
#    run=1
    while swapped:
        swapped = False
#        print ("Run " + str(run))
#        run+=1
        for i in range(len(a)-1):
#            print (a)
            if a[i] > a[i+1]:
                a[i],a[i+1] = a[i+1],a[i] # swap elements
                swapped = True
#        print (a)
    return a

def sort(a):
    print ("Sorting now " + str(a))
    print(bubblesort1(a))
    print(bubblesort2(a))

sort([5,2,7,4,6,1,3])
sort([1,2,3,4,5,6,7,8])
sort([5,4,3,2,1,0,-1])

