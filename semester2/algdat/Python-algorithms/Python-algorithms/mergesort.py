# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the merge sort algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Sorts the input sequence a
# -----------------------------------------------------------------------------
#

from __future__ import print_function
def mergesort(a):
    if len(a) <= 1:
        return a
    middle = len(a)//2
    left, right = a[0:middle], a[middle: len(a)]
    left, right = mergesort(left), mergesort(right)
    # compare last item from left with first item from right
    if left[-1] > right[0]:
        return merge(left, right) 
    else:
        return left + right
    
def merge(left, right):
    result = []
    while len(left) > 0 and len(right) > 0:
        if left[0] <= right[0]:
            result.append(left[0])
            left = left[1:]
        else:
            result.append(right[0])
            right = right[1:]
    if len(left) > 0: # append the rest
        result += left
    else:  
        result += right
    return result

print(mergesort([1, 9, 0, 5, 6, 7, 8, 2, 4, 3]))
