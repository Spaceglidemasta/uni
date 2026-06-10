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

## 2 (01.06.2026)
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

## 2 (08.06.2026) Cracking SHA1 hashes

SHA1 is not secure and can be easily broken with an online tool / DB:

1. 5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8 : password
2. 7c4a8d09ca3762af61e59520943dc26494f8941b : 123456
3. d44ef90413033a0816ecbde55a69d912fcd410f7: _not found in DB of the website I used_
4. 7c222fb2927d828af22f592134e8932480637c0d : 12345678
5. 6367c48dd193d56ea7b0baad25b19455e529f5ee : abc123
6. b1b3773a05c0ed0176787a4f1574ff0075f7521e : qwerty
7. ab87d24bdc7452e55738deb5f868e1f16dea5ace : monkey
8. 19d5a2866d23792ff892a08ac0e65809fb331c94 : mein+passwort
9. b7a875fc1ea228b9061041b7cec4bd3c52ab3ce3 : letmein
10. af8978b1797b72acfff9595a5a2a373ec3d9106d : dragon
11. 3d4f2bf07dc1be38b20cd6e46949a1071f9d0e3d : 111111
12. a2c901c8c6dea98958c219f6f2d038c44dc5d362 : baseball
