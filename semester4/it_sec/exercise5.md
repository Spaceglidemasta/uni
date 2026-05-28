# Exercise 3 (Blockchain)
## 1 Use Cases and Limitations of Blockchain
### a)
1. Bad scenario for a blockchain. A blockchain is immutable, but not really secure towards the contained data and is only really used in decentralized scenarios. It also lacks efficiency.

2. Good scenario for a blockchain. Decentralized situation with immutable, chainable data.

3. Bad idea. Holiday requests may change / are not very keen to beeing immutable.

### b)
The Blockchain trilemma consists of the 3 following aspects of blockchaining:

1. Security:            The blockchain should be secure, and resistant to attacks.
2. Scaleability:        The blockchain should operate efficient, even on bigger scales.
3. Decentralisation:    The blockchain should be decentralized and validateable by many.

Altough Bitcoin and Etherium both implement __Security__ to a high degree, but lack __Scalability__ and __Decentralisation__ respectivly.

If you increase Scalability, you lose out on stronger hardware for validation $\rarr$ higher cost for validation $\rarr$ less people beeing able to run validation $\rarr$ less decentrelisation.

On the other way around, if you want to maximize decentrelisation, you need to restrict hardware / troughput $\rarr$ less Scalability / performance

And if you want to maximize both, youd need to soften security measures in order to increase scaleablity whilest still keeping decentrelisation, sacrificing security in the process.

### c)

The _oracle problem_ is based on the blockchain oracles, which are external factors, which the blockchain needs to blindly trust (because they are external). These are then either exploitet by attackers, or wrong due to hardware or human errors, which leads to false inputs beeing cementet into the blockchain forever. An attack mostly consists of exploiting and temporary overloading these external "oracles" by, for example, drastically in- / deflating small exchange pools, which changes the exchange rate from said pool to the blockchain currency drastically, but just for a short time. However, this short time window is then beeing exploited by the attacker by exchanging between the blockchain currency and the small pool in this small time window for a profit.

### d)

The problem with this right is, that the core principle of the blockchain is immuteability, but if one is to use said right to remove personal data and this data is inside the blockchain, the blockchain must be mutated in order to remove the data, which is a dilemma.

A good and simple approach to this problem is, to not store the user data directly inside the blockchain, but instead on an external server. The blockchain itself only stores a pointer / adress to the data inside said server. If the User then requests a data delete, the data on the server is deleted and the pointer inside the blockchain points on empty data, but is still present and unchanged.

The problem with this is, that the hashed pointer to the data is still a small, but present medium to identify a person, even when it points to nothing. Even if one would move away from ones adress, "The person which used to live at \<Adress>" is still a viable form of identification.

## 2 Hash Functions and Block Chaining
### a)
- Preimage resistance $\rarr$ "cant be undone"
- Collision Resistance $\rarr \forall^- x,y : \text{Hash}(x) \neq \text{Hash}(y)$ 
- Avalanche Effect: $\rarr$ 1 change in value $\rarr$ completly new hash value

#### Preimage resistance
Without Preimage resistance one could alter past transactions, violating the core principle of a blockchain

#### Collision Resistance
The system could not differ between different data, which still has the same hash value. This could be abused by tricking the system into accepting altered data as correct.

#### Avalanche Effect
If 1 change only causes subtle change in the resulting hash value, the attacker could reproduce the hash function, destroying the entire blockchain in the process.

### b)

#### 1.
Block 3 and 4 are invalid. <br>
Block 3 is invalid because its payload and therefore its hash is altered, and block 4 is invalid because its hash depends on the payload in block 3, which is invalid.

#### 2.
Recalcute the hash of block 3 and the previous hash and full hash of block 4

#### 3.
Chaining detects manipulation, but doesnt prevent it. If the attacker changes not only the payload, but every subsequentual hash after that, creating a completely new, valid chain.

### c)
The bigger hashspace of SHA-256/3 allows practical protection against attacks like birthday-attacks or other collision attacks. Also, SHA-1 and MD5 were already broken in the past and known for beeing weak.

### d)
The property which gets broken is __Collision Resistance__. The consequences for the blockchain are, that there a input values for which the hash function produces the same hash value, leading to the inablity to differ between both values, leading to the system assuming that both inputs were the same. This can be used to spoof inputs, tricking the system into thinking you are submitting valid data to the blockchain, while you are activly altering it, breaking the integrity and core princriple of the blockchain. 

## 3 Building your own Blockchain 
### a) Hash functions as the foundation
#### i.
```py
import hashlib as hl

value_Block = hl.sha256(b"Block").hexdigest()

print(f"{value_Block = }")

value_block = hl.sha256(b"block").hexdigest()

print(f"{value_block = }")
```
#### ii.
The output completely changes. This is called the __Avalanche Effect__.

#### iii.
*collision resitance and one way functions were already explained twice*

### b) Data structure and chaining

[Program](./ex5/blockchain.py "Python program for ex b)")

### c) Demonstrating tamper-resistance

#### i.

(Payload of Block 1 was set to "Hello Word")

    (block.hash = '10d8c399a066188c1179a7861f3f660303d40b4751791fde9fa266eede8f4711')
    is not equal to
    (hashed_payload = 'd9745587a212f939a0bd9e929d037c39a55b09901f70d4013a141ea885171507') 
    Blockchain is invalid

#### ii.

    Blockchain is valid

The attacker would need to rehash the hash of the modified block, together with every block after it inside the blockchain.

#### iii.

The blockchain detected change, but didnt prevent it.

In order to fix this, one would need to sign the hash value, authorizing the identity.

### d) Proof of Work

#### ii.

```py
def mine(self, difficulty: int) -> tuple[timedelta, int]:

        start_nonce = self.nonce
        start = datetime.now()

        while(self.hash[:difficulty] != "0" * difficulty):
            self.nonce += 1
            self.recalc_hash()

        self.recalc_hash()

        return datetime.now() - start, self.nonce - start_nonce
```

#### iii.

Program Output:

    ...
    Minging with difficulty 2: 0:00:00.000550
    Minging with difficulty 4: 0:00:00.116174
    Minging with difficulty 6: 0:02:18.294747

#### iv.

The relationship between difficulty and computational effort shows, that the higher the difficulty, the higher the expected time. This, normally, grows with $O(n²)$, but is also heavily influenced by luck, which can be seen with mining step 3

### e) Signing transactions

#### ii.

```py
def verify_signature(self, public_key:Ed25519PublicKey) -> bool:

        try:
            public_key.verify(self.signature, self.payload.encode("latin-1"))
            return True

        except:
            print("WARNING: Verifying signature failed.")
            return False
```

#### iii.

A Blocks Hash detects mutated payloads. A signature detects unauthorized mutating of said Hash values.

The added security property is called __Authentication__.

### f) Challenge: Longest-chain rule and consensus simulation
#### i.
```py
scnd_chain = bc[:3]

scnd_chain.add_block("fork", private_key)
scnd_chain[-1].mine(3)

scnd_chain.add_block("longestchainrule", private_key)
scnd_chain[-1].mine(3)


bc.add_block("challange", private_key)
bc[-1].mine(3)
```

#### ii.
```py
def resolve(a: Blockchain, b: Blockchain) -> Blockchain:
    def work(chain: Blockchain) -> int:
        total = 0
        for block in chain.chain:
            total += int(block.hash, 16)
        return total

    return a if work(a) <= work(b) else b
```
If both chains are the same, the function opts for chain a
#### iii.


The Power of Work rule assumes that more then 50% of "power" comes from honest workers which always use the newest blockchain. In order to outpace the blockchain, the attacker would need to have more then 50%, e.g. __51%__ power, which would allow the attacker to mine faster on average then everybody else.

In order to "rewrite History" the attacker would need to send out a transaction, wait for it to be confirmed by the public chain and secretly mine from another chain from an earlier block. If they catch up to the public chain, their chain becomes the longest and the network switches to it, making the transaction disappear.

The problem is, that even with 51%, the attacker still does not win every race. The attacker needs to outpace the main chain long enough to overtake the it. Also, because the attacker is stuck on their own private chain, the longer they dont win the race, the harder it gets to catch up. This scales __Exponential__ with the number of confirmations made on the main chain, which would make it practically impossible to overtake after a certain time, wasting all computing and transaction resources in the process.