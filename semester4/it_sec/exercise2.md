# Exercise 2

Symmetric Cryptography

Prof. Dr. Robin Müller-Bady

## 1
### a
Sniffing: Confidentialy -> The messages between A and B are not confidential anymore, as a third party (M) can sniff the messages.

Message Modification: Integrity -> M can modify messages between A and B to his will.

Impersonating: Authentication -> M can impersonate as A infront of B, or the other way around

### b
Encryption

Hash Functions / Message Authentication Codes

Digital Signatures

## 2
### a
The security of a cipher should rely on the secrecy of the required key, not the
secrecy of the cipher method

Best example: SHA-256

It is openly known that Bitcoin is encrypted with SHA-256, but the important Part is that the Keys are so secret that a whole are of work (Bitcoin Mining) was created just to find some keys.
It does not mather if the encryption method is known, the key(s) just have to be secret.

### b
Perfect Security is unbreakable, even with unlimited computing power. Practical Security is always breakable with infinite computing power time. Perfect Security does not leak any information, as its perfect. Practical Security always leaks some information.

### c
One-Time-Pad with a random key. The attacker cannot decipher what information is correct without having the key.

"ASDHSD"

can mean

"Yes" / "No" / ... 

dependend on the key

### d
Perfect secure cryptosystems are very expensive in practice. Also, very good practical security is already good enough for reality

## 3

Confusion means to make the relation between key and ciphertext as complex as possible.
This means, that 1 ciphertext bit should depend on multiple key bits.

Operation: Substituion

Diffusion means to spread information from the plaintext over the ciphertext, e.g. when 1 plaintext bit changes, about half of ciphertext bits should change.

Operation: Permutation

## 4

[Hyperlink to Program](ex2/caesar.py)

input =     "no huh se colo vgyycuxj oy zuvykixkz"

output =  [...]  "hi bob my wifi password is topsecret"

## 5

[Hyperlink to Program](ex2/vigenere.py)

input = "ziyt qcl xkm pspqmm dqx gsvvwf qsv fllpmv"

output = "hewz zus zsi nyyito lmv mbncyn mqb odsrur" ?

-> Program is correct, works with codes from the VL

### d

The repeating pattern of the Key inside the ciphered text makes it possible for attackers to reckognize these patterns using frequency analysis, making it possible to recover the key. Most modern encrypting algorithms rely on long, random keys.

### e

[Hyperlink to Program](ex2/challange.py)

#### i

This is an early form of diffusion, because it spreads / diffuses information from 1 point of the plaintext over to other points in the ciphertext. However, this still lacks the characteristic of spreading the 1 point over __multiple__ points in the ciphertext.

#### ii

This is weak compared to other block ciphers like AES, because

1. It doesnt really _diffuse_ information, it just replaces it, while AES uses linear algebra to change symbols bitwise
2. There is only 1 round of "diffusion" over the whole plaintext, while AES has (a lot) more rounds

#### iii
Only one ciphertext letter is changed when changing the plaintext, highlighting that is not really diffusion, as diffusion is defined to spread plaintext information over multiple bits in the ciphertext.

=> The strength of the diffusion is very weak