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
# Binary Tree using tuple representation and (OO) abstract datatype
# -----------------------------------------------------------------------------
#
# -----------------------------------------------------------------------------
# Node (class, struct) representation
# -----------------------------------------------------------------------------
class Node():
    def __init__(self, key, value=0, left=None, right=None):
        self.key = key
        self.value = value
        self.left = left
        self.right = right
        
def search_binary_tree(node, key):
    if node is None:
        return None         # key not found
    if key < node.key:
         return search_binary_tree(node.left, key)
    elif key > node.key:
         return search_binary_tree(node.right, key)
    else:                   # key is equal to node key
         return node.value  # found key

# walk the tree in-order (prints tree "mirrored")
def print_tree(node, indent=""):
    if node is not None:
        indent += "    "
        print_tree(node.left, indent)
        print("%s%s: %s" %(indent[:-4], node.key, node.value))
        print_tree(node.right, indent)
    else:
        print("%s%s" %(indent, "NIL"))
        
# walk the tree pre-order
def print_tree_pre_order(node, indent=""):
    if node is not None:
        print("%s%s: %s" %(indent, node.key, node.value))
        indent += "    "
        print_tree_pre_order(node.left, indent)
        print_tree_pre_order(node.right, indent)
    else:
        print("%s%s" %(indent, "NIL"))

# insert a node into tree
def insert_tree(tree, node):
    y, x = None, tree
    while x is not None:
        y = x
        if node.key < x.key:
            x = x.left
        else:
            x = x.right
    if y == None:
        return node
    elif node.key < y.key:
        y.left = node
    else:
        y.right = node
    return tree

# -----------------------------------------------------------------------------
# tuple representation
# -----------------------------------------------------------------------------
def search_binary_tupletree(tupletree, key):
    if tupletree is None:
        return None             # key not found
    if key < tupletree[0]:
         return search_binary_tree(tupletree[2], key)
    elif key > tupletree[0]:
         return search_binary_tree(tupletree[3], key)
    else:                       # key is equal to node key
         return tupletree[1]    # found key

# construct tree from tuple representation
def constructTree(tpl):
    left, right = None, None
    if tpl[2] is not None:
        left = constructTree(tpl[2])
    if tpl[3] is not None:
        right= constructTree(tpl[3])
    return Node(tpl[0], tpl[1], left, right)


tupletree = (6, 60,
                (5, 50,
                    (2, 20, None, None),
                    (5, 50, None, None)),
                (7, 70,
                    None,
                    (8, 80, None, None)))

tree = constructTree(tupletree)
print("in-oder:")
print_tree(tree)
print(search_binary_tupletree(tupletree, 6))
print("pre-oder:")
print_tree_pre_order(tree)
print(search_binary_tree(tree, 8))
