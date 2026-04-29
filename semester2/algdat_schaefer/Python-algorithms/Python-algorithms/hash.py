# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -------------------


l=["Baden-Württemberg","Bayern","Berlin","Brandenburg","Bremen","Hamburg","Hessen","Mecklenburg-Vorpommern","Niedersachsen","Nordrhein-Westfalen","Rheinland-Pfalz","Saarland", "Sachsen", "Sachsen-Anhalt", "Schleswig-Holstein","Thüringen"]


#the hashtable
t = [None]*13

def hash(s):
    hash = 0
    for i in range(len(s)):
        hash = hash + ord(s[i])
    return hash % 13

def hash_lin(s, i):
    return (hash(s) + i) % 13

def insert_lin(k):
    global t
    i, j = 0, 0
    while True:
        j = hash_lin(k, i)
        if t[j] is None:
            t[j] = k
            return j
        else:
            i = i+1
        if i == 13:
            print("Error: Overflow")
            break

    
print(list(map(hash, l)))

for item in l:
    insert_lin(item)
    print(t)
