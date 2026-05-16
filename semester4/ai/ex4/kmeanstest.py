from sklearn.datasets import make_blobs
import random as r
import matplotlib.pyplot as plt
import numpy as np

K = 3

X, y = make_blobs( # type: ignore
    n_samples=500,
    centers=K,
    cluster_std=2,
    random_state=42
)

def eudist(p1, p2) -> float:

    return np.sqrt(
        (p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2
        )

def groupmean(group:list[tuple[float,float]]) -> tuple[float,float]:

    if (len(group) == 0):
        return (0,0)

    x_sum = sum([p[0] for p in group])
    y_sum = sum([p[1] for p in group])

    return (x_sum / len(group), y_sum / len(group))


x_values = X[:,0]
y_values = X[:,1]

iterations = 5

starter_ks = [
    (r.randint(int(min(x_values)), int(max(x_values))), r.randint(int(min(y_values)), int(max(y_values))))
    for _ in range(K)
    ]

print("Starting points:")
print(starter_ks)

groups:list[list[tuple[float,float]]] = [[] for _ in range(K)]


colors = ["red", "blue", "green", "orange", "purple"]


fig, axes = plt.subplots(1, 6, figsize=(12,4))

xs = [p[0] for p in X]
ys = [p[1] for p in X]
axes[0].scatter(xs, ys, color = "black")
axes[0].set_title(f"Initialisation ({K} clusters)")

#1, +1 because of the first plot on axes[0]
for it in range(1, iterations + 1):
        
    for x, y in zip(x_values, y_values):

        distances:list[float] = []
        
        for meanpoint in starter_ks:

            distances.append(eudist(meanpoint, (x, y)))
        
        mindist = min(distances)

        groups[distances.index(mindist)].append((x,y))

    sxs = [s[0] for s in starter_ks]
    sys = [s[1] for s in starter_ks]
    
    axes[it].set_title(f"Iteration {it}")

    for k in range(K):
        xs = [p[0] for p in groups[k]]
        ys = [p[1] for p in groups[k]]

        axes[it].scatter(xs, ys, color = colors[k])

    axes[it].scatter(sxs, sys, color = "black", s = 100)

    starter_ks = [
        groupmean(groups[k]) for k in range(K)
    ]

    groups = [[] for _ in range(K)]



plt.show()
