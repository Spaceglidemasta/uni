# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the heapsort algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Input a - array to be sorted 
# -----------------------------------------------------------------------------
#
def heapify(a, heapsize, i):
    l = 2*i+1 # lists start with 0!
    r = 2*i+2 # lists start with 0!
    if l < heapsize and a[l] > a[i]:
        maximum = l
    else:
        maximum = i
    if r < heapsize and a[r] > a[maximum]:
        maximum = r
    if maximum != i:
        a[i], a[maximum] = a[maximum], a[i]
        heapify(a, heapsize, maximum)

def build_heap(a):
    for i in range(len(a)//2, 0, -1):
        heapify(a, len(a), i-1)

def heapsort(a):
    build_heap(a)
    for i in range(len(a)-1, 0, -1):
        a[0], a[i] = a[i], a[0]
        heapify(a, i, 0)

# simple routines to print (latex tikz) tree    
def do_print_latex(a, i, indent =""): # walking down the tree
    l = 2*i+1 # lists start with 0!
    r = 2*i+2 # lists start with 0!
    indent += "   "
    if l < len(a):
        print(indent + "child{ node {%i}" % a[l])
        do_print_latex(a, 2*i+1, indent)
        print(indent + "}")
    if r < len(a):
        print(indent + "child{ node {%i}" % a[r])
        do_print_latex(a, 2*i+2, indent)
        print(indent + "}")
		
def print_latex(a):
    print("\\node {%i}" % a[0])
    do_print_latex(a, 0, indent ="")
    print(";")

a=[4,1,3,2,16,9,10,14,8,7]
# print(a)
# build_heap(a)
# print(a)
# #print_latex(a)
# heapsort(a)
# print(a)

def uheapify(a, heapsize, i):
    l = 2*i+1 # lists start with 0!
    r = 2*i+2 # lists start with 0!
    if l < heapsize and a[l] < a[i]:
        maximum = l
    else:
        maximum = i
    if r < heapsize and a[r] < a[maximum]:
        maximum = r
    if maximum != i:
        a[i], a[maximum] = a[maximum], a[i]
        print(a)
        uheapify(a, heapsize, maximum)

def ubuild_heap(a):
    for i in range(len(a)//2, 0, -1):
        uheapify(a, len(a), i-1)

def uheapsort(a):
    ubuild_heap(a)
    for i in range(len(a)-1, 0, -1):
        a[0], a[i] = a[i], a[0]
        uheapify(a, i, 0)




print(f"{a}\n---------------------------------")
ubuild_heap(a)
uheapsort(a)
print(a)

print("")
k = [2, 1, 8, 5, 4, 7, 0, 3, 9]
ubuild_heap(k)

print(k)
