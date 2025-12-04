# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the cut rod algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# 
# -----------------------------------------------------------------------------
#

def cutrod(p, n):
    if n == 0:
        return 0
    q = -1
    for i in range(1, n+1):
        q = max(q, p[i-1] + cutrod(p, n-i))
    return q

def memcutrod(p, n):
    r = [-1]*n
    return memcutrodaux(p, n, r)

def memcutrodaux(p, n, r):
    if r[n-1] >= 0:
        return r[n-1]
    if n == 0:
        q = 0
    else:
        q = -1
        for i in range(1, n+1):
            q = max(q, p[i-1] + memcutrodaux(p, n-i, r))
    r[n-1] = q
    return q

#p = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
p = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 
     17, 17, 20, 24, 30, 17, 17, 20, 24, 27, 
     17, 17, 20, 24, 30, 17, 17, 20, 24, 27, 
     17, 17, 20, 24, 30, 17, 17, 20, 24, 27]
#print(cutrod(p, 10))
print(memcutrod(p, 37))

