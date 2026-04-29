
def foo1(n,m):
    x = 0
    y = 0
    for i in range(n):
        z = 1
        for j in range(1, n + m + 1):
            x = x + z
            y = y + 1
        for k in range(1, n + m + 1):
            y = y - 1
    
    z = 2 * z
    return x + y + z

def foo3(n,m):
    return n * (n + m) +  2


def foo2(n,m):
    return n + m + 1

FIRST = 8
SEC = 5

print(foo1(FIRST,SEC))
print(foo3(FIRST,SEC))
print(foo2(FIRST, SEC))