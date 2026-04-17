# Exercise 11???
##### Theoretical Part
## 1
### a)
A $\rarr$ B
### b)
$A \subseteq B  \land A \rightarrow B$
### c)
$A \rightarrow B \land B \rightarrow C \Rightarrow A \rightarrow C$
## 2
### NF1
Every attribute is Atomic
### NF2
No non-CK is partially dependent on the PK
### NF3
No non-CK is transitive dependent on the PK
## 3
Schüler:
| <ins>SchülerNR</ins> | Name     | Vorname | Klasse |
| -------------------- | -------- | ------- | ------ |
| 1                    | Müller   | Hans    | 9aG    |
| 2                    | Özkan    | Murat   | 10bG   |
| 3                    | Valenti  | Gaetano | 8aH    |
| 4                    | Madmar   | Mohamed | 8aH    |
| 5                    | Florasta | Giusy   | 9aR    |

Klasse
| <ins>Klasse</ins> | Klassenlehrer |
| ----------------- | ------------- |
| 9aG               | Kirchstein    |
| 10bG              | Jocher        |
| 8aH               | Ehlert        |
| 9aR               | Mendez        |


Schüler2Lehrangebot
| <ins>Lehrangebotsnr</ins> | <ins>SchülerNr</ins> | Zeit(h) |
| ------------------------- | -------------------- | ------- |
| 2                         | 2                    | 3       |
| 3                         | 1                    | 4       |
| 3                         | 3                    | 4       |
| 3                         | 5                    | 4       |
| 7                         | 2                    | 2       |
| 7                         | 4                    | 6       |
| 12                        | 3                    | 1       |

Lehrangebot
| <ins>Lehrangebotsnr</ins> | Beschreibung |
| ------------------------- | ------------ |
| 2                         | Englisch     |
| 3                         | Mathe        |
| 7                         | Sport        |
| 12                        | Musik        |