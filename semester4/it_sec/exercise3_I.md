# Exercise 3
## 1
### a

$\text{Signature} = \text{Sign}_{k_{sA}}( H(m) )$,

where $\text{Sign}_{k_{sA}}$ is a Signuture algortihm like $\text{RSA}$ and $H$ is a Hash function like $\text{SHA-256}$ and $m$ is the message.

### b

Alice sends the Signature $s$ together with the message $m$.

### c

Bob uses the corresponding verification algortihm over the public key $k_{pA}$, and compares the resulting Hash Value with $H(m)$, where $H$ is the same hashing function Alice used.

If both match, Alice is (very  likely) the real sender.

### d

Its non-repudational, because, because Bob knows $k_{AB}$ himself, he cannot prove to a __third-party__ that the message was sent by Alice, and not forged by Bob hismelf.

## 2

|              | __Symmetric__                                     | __Asymmetric__               |
| ------------ | --------------------------------------------- | ------------------------ |
| __Pro__    | You only need to store 1 key to en- & decrypt | non-repudiation, higher security          |
| __Contra__ | no non-repudiation                            | you need to store 2 keys |

### c

A hybrid cryptosystem is more efficent / faster and more secure then a standard assymetric one.

The sender has a public key $pk_{R}$, which they share with the reciever, who also has a private key $sk_{R}$. 

The sender creates a session key $k_s$, which they encrypt __asymmetrically__ ($pk_{R}$, $sk_{R}$):

$c_1 = \text{Enc}_{pk_R}(k_s)$

they then encrypt the actual message __symmetrically__ using the session key  and send both the reciever:

$c_2 = \text{Enc}_{k_s}(m)$

$\rightarrow$ ($c_1$, $c_2$)

The reciever then decrypts $c_1$ with the corresponding private key $sk_{R}$, and uses the resulting session key $k_s$ to decrypt $c_1$ to the message $m$:

$k_s = \text{Decr}_{sk_R}(c_1)$

$m = \text{Decr}_{k_s}(c_2)$

This way the message is encrypted and signed, and because part of the process is asymetric, the whole process enjoys the pros of an asymmetric cryptosystem.