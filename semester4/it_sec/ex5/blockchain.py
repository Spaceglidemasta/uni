from __future__ import annotations

import hashlib as hl
import time as t
from datetime import datetime, timedelta
from typing import overload
import copy

from cryptography.hazmat.primitives.asymmetric.ed25519 import Ed25519PrivateKey, Ed25519PublicKey


def hash256(payload:str) -> str:
    return hl.sha256(payload.encode("latin-1")).hexdigest()

class Block:

    def __init__(
            self,
            index:int,
            payload:str,
            previous_hash:str,
            private_key:Ed25519PrivateKey
                 ) -> None:
        self.index = index
        self.timestamp = t.time()
        self.payload = payload
        self.previous_hash = previous_hash
        self.nonce = 0
        self.recalc_hash()
        self.signature = private_key.sign(self.payload.encode("latin-1"))


    def recalc_hash(self):
        self.hash = self.calc_hash()

    def calc_hash(self) -> str:
        return hl.sha256(
                            (
                                str(self.index) +
                                str(self.timestamp) + 
                                self.payload +
                                self.previous_hash +
                                str(self.nonce) 

                            ).encode("latin-1")

                        ).hexdigest()

    def set_payload(self, payload:str):
        self.payload = payload
        self.recalc_hash()

    def mine(self, difficulty: int) -> tuple[timedelta, int]:

        start_nonce = self.nonce
        start = datetime.now()

        while(self.hash[:difficulty] != "0" * difficulty):
            self.nonce += 1
            self.recalc_hash()

        self.recalc_hash()

        return datetime.now() - start, self.nonce - start_nonce

    def __repr__(self) -> str:
        return f"""
BlockChain[{self.index}]:
    timestamp       = {self.timestamp}
    payload         = \"{self.payload}\"
    previous_hash   = {self.previous_hash}
    hash            = {self.hash}
    nonce           = {self.nonce}
    signature       = {self.signature[:20].hex()}...
"""
    
    def verify_signature(self, public_key:Ed25519PublicKey) -> bool:

        try:
            public_key.verify(self.signature, self.payload.encode("latin-1"))
            return True

        except:
            print("WARNING: Verifying signature failed.")
            return False


class Blockchain:

    def __init__(self, pk: Ed25519PrivateKey) -> None:

        payload = ""

        self.chain:list[Block] = [
            Block(
                0,
                payload,
                "0" * 64,
                pk
                )
        ]
        pass

    def add_block(self, payload:str, pk:Ed25519PrivateKey):
        self.chain.append(Block(
            len(self.chain),
            payload,
            self.chain[-1].hash,
            pk
        ))

    #This is the voodoo Terry A. Davis warned us about
    @overload
    def __getitem__(self, key: int) -> Block:...

    @overload
    def __getitem__(self, key: slice) -> Blockchain:...

    def __getitem__(self, key: int | slice) -> Block | Blockchain:

        if isinstance(key, slice):
            newchain = Blockchain.__new__(Blockchain)
            newchain.chain = [copy.copy(b) for b in self.chain[key]]
            return newchain
        else:
            return self.chain[key]
    
    def __setitem__(self, key, value:Block):
        self.chain[key] = value

    def __delitem__(self, key):
        self.chain.__delitem__(key)


    def is_valid(self) -> bool:

        last_hash = "0" * 64

        for block in self.chain:

            if block.hash != (hashed_payload:=block.calc_hash()):

                print(f"({block.hash = })\nis not equal to\n({hashed_payload = }) ")

                return False
    
            if block.previous_hash != last_hash:

                print(f"{block.previous_hash = }\nis not equal to\n{last_hash = } ")

                return False
            
            last_hash = block.hash

        return True

    def __repr__(self) -> str:
        return "\n".join([block.__repr__() for block in self.chain])
    

def resolve(a: Blockchain, b: Blockchain) -> Blockchain:
    def work(chain: Blockchain) -> int:
        total = 0
        for block in chain.chain:
            total += int(block.hash, 16)
        return total

    return a if work(a) <= work(b) else b



if __name__ == "__main__":

    private_key =  Ed25519PrivateKey.generate()
    public_key = private_key.public_key()

    bc = Blockchain(private_key)
    bc.add_block("Hello World", private_key)
    bc.add_block("This is a blockchain", private_key)
    bc.add_block("lorem ipsum", private_key)

    print(bc)

    td2, nonce2 = bc[-1].mine(2)
    td4, nonce4 = bc[-1].mine(4)
    #td6, nonce6 = bc[-1].mine(6)

    print(f"Mining with difficulty 2 is done after {nonce2} nonces in {td2}")
    print(f"Mining with difficulty 4 is done after {nonce4} nonces in {td4}")
    #print(f"Mining with difficulty 6 is done after {nonce6} nonces in {td6}")

    #bc[1].payload = "Hello Word"

    print()
    print("Blockchain is valid" if bc.is_valid() else "Blockchain is invalid")

    #bc[1].signature = bytes(0x3)

    print("Signature is valid" if bc[1].verify_signature(public_key) else "Signature is invalid")

    scnd_chain = bc[:3] #this is so much code internally
    scnd_chain.add_block("fork", private_key)
    scnd_chain[-1].mine(3)
    scnd_chain.add_block("longestchainrule", private_key)
    scnd_chain[-1].mine(3)

    bc.add_block("challange", private_key)
    bc[-1].mine(3)

    print("\nBlockchain forked.")

    winner = resolve(bc, scnd_chain)

    print(winner)    

    


