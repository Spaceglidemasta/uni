from vigenere import vigenere


def alicnbob(ptext:str) -> str:

    out = ""

    for i in range(0, len(ptext), 4):
        block = ptext[i:i+4]

        if len(block) < 4:
            out += block
        else:
            out += block[2] + block[0] + block[3] + block[1]


    return out


if __name__ == "__main__":
    
    ptext:str = "THEYDRINKTHETEA"
    key:str = "DUH"
    opmode:int = True

    vig:str = vigenere(ptext, key, opmode)

    print(vig)
    print(alicnbob(vig))

    