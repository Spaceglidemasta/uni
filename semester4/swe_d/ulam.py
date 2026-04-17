

def collatz(n:int) -> None:


    if n == 1:
        print(" Done!")
        return

    if n % 2 == 0:
        collatz(n // 2)
    else:
        collatz(3 * n + 1)


if __name__ == "__main__":
    
    for i in range(1, 1_000_001):
        print(f"Collatz: {i}", end = "")
        collatz(i)