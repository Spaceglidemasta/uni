# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
#
# -----------------------------------------------------------------------------
# Examples illustrating recursion
# -----------------------------------------------------------------------------
#
def odd(n):
    if n==0:
        return False
    else:
        return even(n-1)

def even(n):
    if n==0:
        return True
    else:
        return odd(n-1)

def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n-2) + fib(n-1)
    
def fib_iter(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    a, b = 0, 1
    while n >= 2:
        c = a+b
        a, b = b, c
        n = n-1
    return b

# maccarty = 91 for all n <= 101 (proof?!)
def mccarty91(n):
    if n > 100:
        return n -10
    else:
        return mccarty91(mccarty91(n+11))
    
print("even(234): %s" % even(234))
print("even(233): %s" % even(233))
print("odd(7): %s" % odd(7))

print("fib(23)=%i" % fib(23))
print("fib_iter(23)=%i" % fib_iter(23))
