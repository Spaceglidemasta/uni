

class msg:

    def __init__(self, value:int):
        self.value = value
        pass

    def __add__(self, other):
        return self.value + other.value


if __name__ == "__main__":  
    a = msg(5)
    b = msg(10)
    c = a + b
    print(c)
