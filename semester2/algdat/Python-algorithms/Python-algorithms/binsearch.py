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
# Binary search of an element in a list
# -----------------------------------------------------------------------------
#

def binsearch(a, l, r, k):
	if r < l:
		return False
	mid = int((l+r)/2)
	if k == a[mid]:
		return True
	elif k < a[mid]:
		return binsearch(a, l, mid-1, k)
	else:
		return binsearch(a, mid+1, r, k)
		
l = [1,4,6,7,8,13,15,16,18,23,32,33,38,45]

print(binsearch(l, 0, len(l)-1, 4))
print(binsearch(l, 0, len(l)-1, 9))
print(binsearch(l, 0, len(l)-1, 23))
print(binsearch(l, 0, len(l)-1, 7))
print(binsearch(l, 0, len(l)-1, 1))
print(binsearch(l, 0, len(l)-1, 45))
print(binsearch(l, 0, len(l)-1, 49))
print(binsearch(l, 0, len(l)-1, -1))
