
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd





def collatz(n:int, depth:int = 0) -> int:


    if n == 1:
        print(f" Done! {depth=}")
        return depth

    if n % 2 == 0:
        return collatz(n // 2, depth + 1)
    else:
        return collatz(3 * n + 1, depth + 1)


if __name__ == "__main__":

    depthxy:list[int] = []
    
    for i in range(1, 1001):

        print(f"Collatz {i=}:", end = "")
        depthxy.append(collatz(i))

    df = pd.DataFrame({
        "n": range(1, 1001),
        "depth": depthxy
    })

    sns.regplot(data=df, x = "n", y = "depth")
    plt.show()


