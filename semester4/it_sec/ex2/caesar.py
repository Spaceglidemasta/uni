


def caesar(instr:str, key:int, encrypt: bool = True) -> str:
    out = ""

    for char in instr:

        if not char.isalpha():

            out += char

            continue

        base = ord("a") if char.islower() else ord("A")

        
        out += chr((ord(char) - (base + key if encrypt else base - key)) % 26 + base)

    return out



if __name__ == "__main__":

    for i in range(1,27):
        print(f"{i:2}: {caesar("no huh se colo vgyycuxj oy zuvykixkz", i, True)}")