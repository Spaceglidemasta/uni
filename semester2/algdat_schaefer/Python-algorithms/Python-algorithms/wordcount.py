#!/usr/local/bin/python
# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Frequency count of words in a file
# -----------------------------------------------------------------------------
#
import sys

def wc(filename):
    wc = {}
    f = open(filename, encoding='latin1')
    for line in f.readlines():
        words = line.split(" ")
        for word in words:
            if word in wc:
                wc[word] += 1
            else:
                wc[word] = 1
    f.close()
    return wc

def get_count(counts):
    max_count = 0
    max_word = ""
    for key in list(counts.keys()):
        if counts[key] > max_count:
            max_count = counts[key]
            max_word = key
    return max_word, max_count

def mergesort(a, comp):
    if len(a) <= 1:
        return a
    middle = len(a)//2
    left, right = a[0:middle], a[middle: len(a)]
    left, right = mergesort(left, comp), mergesort(right, comp)
    # compare last item from left with first item from right
    if comp(left[-1], right[0]):
        return merge(left, right, comp) 
    else:
        return left + right
    
def merge(left, right, comp):
    result = []
    while len(left) > 0 and len(right) > 0:
        if comp(right[0], left[0]):
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

counts = wc(sys.argv[1])
print("Word \"%s\" has max count %i" % get_count(counts))

sortedwords = mergesort(list(counts.keys()), lambda x, y: counts[x] < counts[y])
for i in range(10):
    word = sortedwords[i]
    print("Word \"%s\" has count %i" % (word, counts[word]))
