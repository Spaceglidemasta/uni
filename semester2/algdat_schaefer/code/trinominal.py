

def tri(n:int, k: int):
    if(abs(k) == n):
        return 1
    elif(abs(k) > n):
        return 0
    else:
        return tri(n-1, k-1) + tri(n-1, k) + tri(n-1, k+1)


print("| n\k || -3|| -2|| -1|| 0 || 1 || 2 || 3 |")
print("|-----||---++---++---++---++---++---++---|")
for j in range(0,4):
    print(f"|  {j}  |",end = "")
    for i in range(-3, 4):
        print(f"| {tri(j,i)} |", end="")
    print("")