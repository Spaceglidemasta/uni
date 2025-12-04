# -*- coding: utf-8 -*-
#
# Author: Jens Liebehenschel (2016-2020)
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the recursive version of the LCS algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Input x, y strings LCS to select from 
# -----------------------------------------------------------------------------
#

def lcs(x,y):
    if x == "" or y == "":
        return ""
    else: # x and y possess at least one character
        xAllButOne, xLast = x[0:-1], x[-1]
        yAllButOne, yLast = y[0:-1], y[-1]

        if xLast == yLast:
            return lcs(xAllButOne, yAllButOne) + xLast
        else:
            lcs1 = lcs(xAllButOne, y)
            lcs2 = lcs(x, yAllButOne)
            if len(lcs1) > len(lcs2):
                return lcs1
            else:
                return lcs2

x="TGCGTCCATT"
y="ACCGTTGCGTCCAGCTGC"
#x="STUVW"
#y="UVWX"
#x="TGCGTCCAT"
#y="TACGTGCGCT"
lcsResult = lcs(x, y)
print("LCS:", lcsResult, "\n")

# nice output with greedy approach, we take the first match of lcsResult[i] in x and y
xOutput=""
yOutput=""
lcsOutput=""
iX=0 # index for x
iY=0 # index for y
iXPrev=0 # index for x in previous loop
iYPrev=0 # index for y in previous loop

for i in range(len(lcsResult)):
    iXPrev = iX
    while(x[iX]!=lcsResult[i]):
        xOutput += x[iX]
        iX += 1

    iYPrev = iY
    while(y[iY]!=lcsResult[i]):
        yOutput += y[iY]
        iY += 1

    # now x[iX] == y[iY] == lcsResult[i]
    numSpaces = max(iX-iXPrev, iY-iYPrev)

    xOutput += " "*(numSpaces-(iX-iXPrev))
    yOutput += " "*(numSpaces-(iY-iYPrev))

    lcsOutput += " "*(numSpaces)
    lcsOutput += lcsResult[i]
    xOutput += x[iX]
    iX += 1
    yOutput += y[iY]
    iY += 1

# add remaining characters
xOutput += x[iX:]
yOutput += y[iY:]

# calculate first and last row
row = ""
for i in range(len(lcsOutput)):
    if lcsOutput[i] != " ":
        row += "*"
    else:
        row += " "

# output
print(row)
print(xOutput)
print(lcsOutput)
print(yOutput)
print(row)
