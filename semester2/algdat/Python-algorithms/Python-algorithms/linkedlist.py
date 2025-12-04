# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -------------------

def addNode(list, node):
    node[1] = list
    return node


def list_print(list):
    print(list[0])
    if list[1]:
        list_print(list[1])


def list_print_it(list):
    nextnode = list
    while nextnode:
        print(nextnode[0])
        nextnode = nextnode[1]

node1 = ["node1", None]
node2 = ["node2", None]
node3 = ["node3", None]
node4 = ["node4", None]
l = node1
l = addNode(l, node2)
l = addNode(l, node3)
l = addNode(l, node4)

list_print(l)
