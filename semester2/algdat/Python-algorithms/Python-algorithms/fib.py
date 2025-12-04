# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -------------------

# inefficient recursive version of fib
def fib(n):
    if n==1 or n==2:
        return 1
    else:
        return fib(n-1) + fib(n-2)
    


# iterative version of fib simulates call stack with 
# explicit stack but uses accumulator ("+")
# this is as inefficient as recursive version, of course
def fib_iter(n):
    s = []
    s.append(n)
    res = 0
    while len(s) != 0:
        a = s.pop()
        if a==1 or a==2:
            res = res + 1
        else:
            s.append(a-1)
            s.append(a-2)
    return res

# iterative version of fib simulates call stack with 
# explicit stack, no accumulator, but "return addresses"
# this is as inefficient as recursive version, of course
def fib_iter2(n):
    if n==1 or n==2:
        return 1
    s = []
    frame = [n, 0, 0, 0] # a stack frame for n, f(n-1), f(n-2) and "return address" 
    s.append(frame)
    while len(s) != 0:
        f = s[-1]
        n, n1, n2, r = f[0], f[1], f[2], f[3]
        if n1 > 0 and n2 > 0:           # both calls to f(n-1) and (fn-2) have returned
            s[len(s)-r-1][r] = n1 + n2  # so we can compute result and put it into proper "return address"
            frame = s.pop()             # remove frame from computation
        else:
            if n==1 or n==2:
                s[len(s)-r-1][r] = 1    # initial condition
                frame = s.pop()         # remove frame from computation
            else:
                s.append([n-1,0,0,1])   # "recursive call" to f(n-1)
                s.append([n-2,0,0,2])   # "recursive call" to f(n-2)
    return frame[1]+frame[2]

print(fib(13))
print(fib_iter(13))
print(fib_iter2(13))
