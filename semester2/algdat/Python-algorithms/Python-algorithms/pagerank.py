# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -------------------

def matrixMult(A, B):
    nrows = len(A)
    ncols = len(B[0])
    C = [[0 for i in range(ncols)] for j in range(nrows)]
    for i in range(nrows):
        for j in range(ncols):
            for k in range(len(A[0])):
                C[i][j] += A[i][k]*B[k][j]
    return C

def power(A, k):
    B = A
    for i in range(k-1):
        B = matrixMult(B, A)
    return B

def vec2matrix(v):
        return [[x,] for x in v]

def printMatrix(m):
    for i in range(len(m)):
        print(m[i])

if __name__ == '__main__':
        H = [[0,0,0,0,0,0, 1/3.0, 0],
             [0.5,0,0.5,1/3.0,0,0, 0, 0],
             [0.5,0,0,0,0,0, 0, 0],
             [0,1,0,0,0,0, 0, 0],
             [0,0,0.5,1/3.0,0,0, 1/3.0, 0],
             [0,0,0,1/3.0,1/3.0,0, 0, 0.5],
             [0,0,0,0,1/3.0, 0,0, 0.5],
             [0,0,0,0,1/3.0,1, 1/3.0, 0]]
        print("Google Matrix:")
        printMatrix(H)
        print("EV")
        printMatrix(matrixMult(power(H, 40),
             vec2matrix([1/8.0,1/8.0,1/8.0,1/8.0,1/8.0,1/8.0,1/8.0,1/8.0])))
        
