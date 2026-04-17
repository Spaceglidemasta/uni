
from typing import Callable

def derivative(fun: Callable[[float], float]) -> Callable[[float], float]:
    
    min = 1e-5

    def deriv(x:float):
        return (fun(x + min) - fun(x - min)) / (2*min)
    
    deriv.__name__ = fun.__name__ + "_derivative"

    return deriv


def sim(fun:Callable[[float], float], n:int = 20, mirrored: bool = False) -> None:
    print(fun.__name__)
    
    print(
        ", ".join(
            [f"{round(fun(i), 2):g}" for i in (range(-n//2, n//2) if mirrored else range(n))]
        )
    )


if __name__ == "__main__":

    def cubed(x:float) : return x**3

    quad = derivative(cubed)

    lin = derivative(quad)

    sim(cubed, 10, True)
    sim(quad, 10, True)
    sim(lin, 10, True)



