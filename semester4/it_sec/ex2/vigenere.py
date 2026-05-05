


def vigenere(ptext: str, key: str, encrypt: bool = True) -> str:

    out = ""
    key = key.upper()
    key_index = 0

    for char in ptext:

        if not char.isalpha():
            out += char
            continue

        base = ord("a") if char.islower() else ord("A")

        key_shift = ord(key[key_index % len(key)]) - ord('A')

        shift = key_shift if encrypt else -key_shift

        out += chr((ord(char) - base + shift) % 26 + base)

        key_index += 1

    return out


if __name__ == "__main__":
    
    ptext:str = "ziyt qcl xkm pspqmm dqx gsvvwf qsv fllpmv"
    key:str = "security"
    opmode:int = False

    print(vigenere(ptext, key, opmode))



