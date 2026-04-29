# -*- coding: utf-8 -*-
#
# Author: Jörg Schäfer (2010-2020), <jschaefer at fb2.fra-uas.de>
# Frankfurt University of Applied Sciences# FB2, Computer Science and Engineering, Distributed Systems
#
# Illustrates the activity selection algorithm 
# (see Cormen et al, Introduction to algorithms)
# 
# For educational purpose only (not necessarily very pythonic) 
# Requires python 3.0 or higher
#
# -----------------------------------------------------------------------------
# Requires input a to be sorted, returns maximum number of compatible activties
# -----------------------------------------------------------------------------
#

def activity_sel(a, i, n):
	m = i+1
	l = []
	while m <= n and a[m][0] < a[i][1]: # search for first activity
		m = m+1
	if m < n:
		l += [m] # for result, store index only
		return  l + activity_sel(a, m, n)
	else:
		return []
def adjust(a):
    # add s_0 and s_n+1, 999999999 representing infinity 
    return [[0,0]] + a + [[len(a), 999999999]]

a = [[1,4],[3,5],[0,6],[5,7],[3,8],[5,9],[6,10],[8,11],[8,12],[2,13],[12,14]]
print(activity_sel(adjust(a), 0, len(a)+1))
