#!/usr/local/bin/python
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
# FB2, Computer Science and Engineering, Distributed Systems
#
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Red-Black Self Balancing Binary Tree using (OO) abstract datatype
# -----------------------------------------------------------------------------
#
# Implementation is based on the Okasakis ideas in
#
# http://www.eecs.usma.edu/webs/people/okasaki/jfp99.ps
#
# After recursively inserting a node into the binary tree using the insert function
# the red black properties are restored using the balance function.
#
# Implementation uses explicit parent pointers. Could be improved by passing a stack
# of nodes traversed during the insert procedure to the balance function.  
#

BLACK="B"
RED="R"

# -----------------------------------------------------------------------------
# Node (class, struct) representation
# -----------------------------------------------------------------------------
class Node():
    def __init__(self, key, left=None, right=None, color=RED):
        self.key = key
        self.left = left
        self.right = right
        self.color = color
        self.parent = None
    def __str__(self):
         return "%i" % self.key
               
# insert a node x into tree, initial call with r=tree.root (y = r's parent node)
def insert(r, x, y=None):
    r = ins(r, x, y)
    r = balance(x)
    return r

# recursively inserting x into tree and maintaining all pointers (incl. parent pointers)
def ins(r:Node, x:Node, y:Node=None):
    if r is None:
        x.color = RED
        r = x
        r.parent = y
    else:
        if x.key < r.key:
            r.left = ins(r.left, x, r)
        else:
            r.right = ins(r.right, x, r)
    return r

# recursively (re-) balancing tree to maintain red-black invariants
# attention: x, y, z are consistently labelled and different from Okasaki's fig 1!
def balance(x:Node):
    y:Node = x.parent
    if y is None:                               # color root always black
        x.color = BLACK
        return x
    z:Node = y.parent
    if z is None:                               # color root always black
        y.color = BLACK
        return y
    if x.color == RED and y.color == RED:       # need to restore red black prop.
        if x.key < y.key and y.key < z.key:     # case 1 script AlgDat.pdf (fig 1 west in Okasaki)
            print("case1")
            x.color = z.color = BLACK
            z.left = y.right
            y.right = z
            y, _ = _make_child(y, z.parent)           
            z.parent = y
            return balance(y)
        elif x.key > y.key and y.key < z.key:   # case 2 script AlgDat.pdf (fig 1 north in Okasaki)
            print("case2")
            y.color = z.color = BLACK
            y.right = x.left
            x.left = y
            z.left = x.right
            x.right = z
            x, _ = _make_child(x, z.parent)
            z.parent = x
            y.parent = x
            return balance(x)
        elif x.key < y.key and y.key >= z.key:  # case 3 script AlgDat.pdf (fig 1 south in Okasaki)
            print("case3")
            y.color = z.color = BLACK
            y.left = x.right
            x.right = y
            z.right = x.left
            x.left = z           
            x, _ = _make_child(x, z.parent)
            z.parent = x
            y.parent = x            
            return balance(x)
        elif x.key > y.key and y.key >= z.key:  # case 4 script AlgDat.pdf (fig 1 east in Okasaki)
            print("case4")
            x.color = z.color = BLACK
            z.right = y.left
            y.left = z
            y, _ = _make_child(y, z.parent)
            z.parent = y
            return balance(y)
    else:                                       # default
        return balance(y)

# helper function make x child of y adjusting all pointers  
def _make_child(x:Node, y:Node):
    x.parent = y
    if y is not None:        
        if x.key < y.key:
            y.left = x
        else:
            y.right = x
    return x, y

# walk the tree in-order (prints tree "mirrored")
def print_tree(node:Node, indent=""):
    if node is not None:
        indent += "    "
        print_tree(node.left, indent)
        print("%s%s:%s" %(indent[:-4], node.color, node.key))
        print_tree(node.right, indent)
    else:
        print("%s%s" %(indent, "NIL"))

# insert into the tree from a list
def insert_list(l):
    t = None
    for i in l:
        t = insert(t, Node(i))
    return t
    
  
t = None
t = insert(t, Node(10))
t = insert(t, Node(2))
t = insert(t, Node(6))
t = insert(t, Node(1))
t = insert(t, Node(7))
t = insert(t, Node(5))
t = insert(t, Node(8))
t = insert(t, Node(15))
#t = insert(t, Node(20))
#t = insert(t, Node(26))
print_tree(t)

t = insert_list([29, 42, 16, 33, 23, 25, 37, 50, 17, 51, 10, 30, 14, 45, 7])
print_tree(t)
