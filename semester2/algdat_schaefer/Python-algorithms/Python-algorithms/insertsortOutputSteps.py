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

def insertsortOutputSteps(a):
    execForLoop = 0
    execWhileLoop = 0
    condCheckForLoop = 0
    condCheckWhileLoop = 0
    print("Before sorting: " + str(a))
    condCheckForLoop += 1
    for j in range(1, len(a)):
        execForLoop += 1
        condCheckForLoop += 1
        key = a[j]
        print("j=" + str(j) + ", key=" + str(key))
        i = j-1
        condCheckWhileLoop += 1
        while i >= 0 and a[i] > key:
            execWhileLoop += 1
            condCheckWhileLoop += 1
            a[i+1] = a[i]
            print("i=" + str(i) + ", a[" + str(i+1) + "]=a[" + str(i) + "]: " + str(a))
            i = i-1
        a[i+1] = key
        print("                " + str(a))
    print("                # elements = " + str(len(a)))
    print("                # condition checks for-loop = " + str(condCheckForLoop))
    print("                # executions for-loop = " + str(execForLoop))
    print("                # condition checks while-loop = " + str(condCheckWhileLoop))
    print("                # executions while-loop = " + str(execWhileLoop))
    return a

# determine the numbers of loop executions
# for sorted arrays
for i in range(1,11):
    l = list(range(1,i+1))
    insertsortOutputSteps(l)
    print()
# for sorted arrays - reverse order
for i in range(1,11):
    l = list(range(i,0,-1))
    insertsortOutputSteps(l)
    print()

#insertsortOutputSteps([2,4,3,1])
#insertsortOutputSteps([5,2,7,4,6,1,3])

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

#print(insertsort([5,2,7,4,6,1,3]))
#print(insertsort2([5,2,7,4,6,1,3]))
#print(insertsortrec(0,[5,2,7,4,6,1,3]))

