# -*- coding: utf-8 -*-
#
# Author: Jens Liebehenschel, Jörg Schäfer (2019-2020)
# Frankfurt University of Applied Sciences
# FB2, Computer Science and Engineering, Distributed Systems
# 
# For educational purpose only (not necessarily very pythonic) 
#
# -------------------

# algorithm 3.6 in script (2019)
def schleife2(n):
    k = 0
    for j in range(n):
        for i in range(j+1):
            k = k + i
    return k

# determination of the value in O(1)
def schleife2wert(n):
    wert = n*(n*n-1)
    if wert % 6 != 0:
        print ("ERROR")
        return -1
    else:
        return wert//6

# for testing purposes
for n in range(10):
    print(n, schleife2(n), schleife2wert(n))
