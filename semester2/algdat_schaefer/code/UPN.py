from __future__ import annotations
from typing import Callable
import inspect
import math

#TRENNZEICHEN HIER EINSTELLEN:
SEPERATOR = " "
DEBUG = True


class Operator:

    def __init__(self,
                 symbol:str,
                 grade:int,
                 fun: Callable[..., float]
                 ) -> None:
        
        self.symbol = symbol
        self.grade = grade
        self.fun = fun

        count:int = 0;
        for param in inspect.signature(fun).parameters.values():
            if param.kind in (
                inspect.Parameter.POSITIONAL_ONLY,
                inspect.Parameter.POSITIONAL_OR_KEYWORD
            ):
                count += 1
        
        if(count != grade):
            raise Exception("Grade needs to be equal to the amount of parameters")

    
    def __eq__(self, other: Operator) -> bool:
        '''
        Operator overloading for ==
        '''
        return self.symbol == other.symbol
    
    
    def evaluate(self, *ins: float) -> float:
        return self.fun(*ins)
        



def calculate(tokens: list[str], arith: dict[str, Operator]) -> float:
    stack: list[float] = []

    for token in tokens:
        if token in arith:
            op = arith[token]

            if len(stack) < op.grade:
                raise ValueError("Not enough operands")

            args = stack[-op.grade:]
            del stack[-op.grade:]

            result = op.evaluate(*args)
            stack.append(result)
        else:
            stack.append(float(token))

    if len(stack) != 1:
        raise ValueError("Invalid UPN expression")

    return stack[0]



    
    
            


if __name__ == "__main__":

    
    plus:Operator = Operator("+",
                             2,
                             lambda a, b : a + b)
    
    sub: Operator = Operator("-",
                             2,
                             lambda a, b : a - b)
    
    mult:Operator = Operator("*",
                             2,
                             lambda a, b : a * b)
    
    divide: Operator = Operator("/",
                             2,
                             lambda a, b : a / b)
    
    power:Operator = Operator("**",
                             2,
                             lambda a, b : a ** b)
    
    # trigonometry

    sin: Operator = Operator("sin",
                             1,
                             lambda a : math.sin(a))
    
    cos: Operator = Operator("cos",
                             1,
                            lambda a : math.cos(a))
    
    tan: Operator = Operator("tan",
                             1,
                            lambda a : math.tan(a))
    
    sqrt: Operator = Operator("sqrt",
                              1,
                              lambda a: math.sqrt(a))
    

    arithmetics: dict[str, Operator] = {
        "+" : plus,
        "-" : sub,
        "*" : mult,
        "/" : divide,
        "**" : power,
        "sin" : sin,
        "cos" : cos,
        "tan" : tan,
        "sqrt" : sqrt
        }

    upn = input("Geben Sie ein arithmetischen Ausdruck in UPN an: ")
    upn = upn.split(SEPERATOR)

    #Beispiel Eingabe: 2 3 * 4 5 + - 5 4 * /    => -0.15
    #Bitte trennzeichen einstellen
    print(calculate(upn, arithmetics))







