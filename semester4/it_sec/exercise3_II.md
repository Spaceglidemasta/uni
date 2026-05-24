# Exercise 3 II
## 1
### a
- Deterministic
- Efficient / Fast
- Avalanche Effect (1 Change -> Completely differen output)

### b
- Detecting changes in files (git)
- Password storage
- Signatures

## 2
### a
The problem is, that the sender encrypts the hash value using the __public key__. (Step 2)

This leads to complete failure of _authenticity_, because the Reciever does not know if the sender is really who he thinks he is if the key is public. Because of this, the _integrity_ is also endangered, as the document couldve been changed and then hashed again using the available public key.

### b
<p>
A: Student <br>
B: Reciever
</p>

1. A computes the Hash Value of the Document and prepares a public and private key.
2. A __asymmetrically__ signs the Hash Value using A's own private key. This can only be unsigned using the public key of A.
3. A sends Signed Hash Value & Document
4. B unsignens Hash Value using A's public key.
5. B computes the Hash Value of the Document and compares it to the unsigned Hash Value A sent.
6. If both are the same, authenticity and integrity, together with non-repudation, are present.

