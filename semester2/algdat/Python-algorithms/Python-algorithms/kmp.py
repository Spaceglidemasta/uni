# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the Knuth-Morris-Pratt Algorithm algorithm 
# (see Cormen et al, Introduction to algorithms)
#
# Also illustrates the simple FSM approach
#
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Finds all occurence of pattern p in text t
# -----------------------------------------------------------------------------
#
# -----------------------------------------------------------------------------
# LATEX and Graphviz dot auxiliary functions
# -----------------------------------------------------------------------------
#
# generate dot graph from transition_function ts
def print_dot(ts):
    for node in set([x[0] for x in list(ts.keys())]):
        print("%s;" % node)
    for key in list(ts.keys()):
        print("%s -> %s [label=%s];" %(key[0], ts[key], key[1])) # using %s to support string labels for nodes

# print LaTex table for transition_function corresponding to pattern p and alphabet s
def print_table(p, s):
    ts = compute_transition_function(p, s)
    p = p + " " #dummy for last row
    for i in range(0, len(p)):
        tpl = "%i&%s&%s\\cr\\hline"
        print(tpl %(i, "&".join([str(ts[(i, s[x])]) for x in range(0, len(s))]), p[i]))    


# -----------------------------------------------------------------------------
# Simple FSM
# -----------------------------------------------------------------------------
#
def compute_transition_function(p, s):
    d = {}
    m = len(p)
    for q in range(0, m+1):
        for a in s:
            k = min(m+1, q+2)
            suffix = False
            while not suffix:
                k = k-1
                pa = p[:q] + a
                if pa[q-k+1: q+1] == p[:k]:
                    suffix = True # P_k is suffix of P_q
            d[(q,a)] = k
    return d

def fsm_matcher(t, d, m):
    n = len(t)
    q = 0
    for i in range(n):
        q = d[(q, t[i])]
        if q == m:
            print("match at: %i" % (i - m + 1))

#
# -----------------------------------------------------------------------------
# KMP
# -----------------------------------------------------------------------------
#
def compute_prefix_function(p):
    m = len(p)
    pi = [0] * m
    k = 0
    for q in range(1, m):
        while k > 0 and p[k] != p[q]:
            k = pi[k-1]
        if p[k] == p[q]:
            k = k + 1
        pi[q] = k
    return pi

def kmp_matcher(t, p):
    n = len(t)
    m = len(p)
    pi = compute_prefix_function(p)
    q = 0
    for i in range(n):
        while q > 0 and p[q] != t[i]:
            q = pi[q-1]
            print("i: %i, while loop, adjusting state:%i" %(i, q))
        if p[q] == t[i]:
            q = q + 1
        print("i: %i, state:%i" %(i, q))
        if q == m:
            print("match at: %i" % (i - m + 1))
            q = pi[q-1]

text = "cdfababacasdfsd"
pattern = "ababaca"
print("text: %s, pattern: %s" %(text, pattern))
print("kmp:")
kmp_matcher(text, pattern)
print("fsm:")
d = compute_transition_function(pattern, "abcdefs")
fsm_matcher(text, d, len(pattern))

#ts = compute_transition_function("ababaca", "abc")
#print_dot(ts)

