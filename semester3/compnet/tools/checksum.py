
def check_if_valid_binnum(inp:str):
    for el in inp:
        if el not in ["0", "1"]:
            print("Wrong input.")
            exit()


inp = input("Number in binary:")

check_if_valid_binnum(inp)

bitlist = [int(el) for el in inp]



inp = input("Poly in binary:")

check_if_valid_binnum(inp)

polylist = [int(el) for el in inp]


if __name__ == "__main__":

    print(bitlist)
    print(polylist)
