count = 0
ncount = 0

dic =  {}



def tri(n: int,k: int):
    global count, ncount
    count += 1
    if k == 0 or k == n:
        return 1
    elif (n,k) in dic:
        return dic[(n,k)]
    else:
        trig = tri(n - 1, k) + tri(n - 1, k - 1) + tri(n, k - 1)
        dic[(n,k)] = trig
        ncount += 1
        return trig
    
print(tri(7,4))
print(count)
print(ncount)

