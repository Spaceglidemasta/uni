# Exercises: Propositional Resolution

## 1
### a
$( \lnot p  \lor  q)  \land  (r  \lor   \lnot s)  \land  ( \lnot p  \lor   \lnot q)$

###### (Already NNF)

### b
$(( \lnot p  \lor  q)  \land  (r  \lor   \lnot s)) →  \lnot ( \lnot p  \lor   \lnot q)$

$=(( \lnot p  \lor  q)  \land  (r  \lor   \lnot s)) → (p  \land  q)$

$= \lnot (( \lnot p  \lor  q)  \land  (r  \lor   \lnot s))  \lor  (p  \land  q)$

$=( \lnot ( \lnot p  \lor  q)  \lor   \lnot (r  \lor   \lnot s))  \lor  (p  \land  q)$

$=(p  \land   \lnot q)  \lor  ( \lnot r  \land  s)  \lor  (p  \land  q)$



### c

Note:

$A ↔ B = (A→B) \land (B→A) = ( \lnot A \lor B) \land ( \lnot B \lor A)$

This means:

$( \lnot p  \lor  q) ↔ ( \lnot r  \land  s)$

$=(( \lnot p  \lor  q) → ( \lnot r  \land  s)) \land (( \lnot r  \land  s)→( \lnot p  \lor  q))$

$=( \lnot ( \lnot p  \lor  q)  \lor  ( \lnot r  \land  s)) \land ( \lnot ( \lnot r  \land  s) \lor ( \lnot p  \lor  q))$

$=((p  \land   \lnot q)  \lor  ( \lnot r  \land  s)) \land ((r  \lor   \lnot s) \lor ( \lnot p  \lor  q))$

## 2
### a
$( \lnot p  \lor  q)  \land  (r  \lor   \lnot s)  \land  ( \lnot p  \lor   \lnot q)$´
###### (Already CNF)

### b
$(p  \land   \lnot q)  \lor  ( \lnot r  \land  s)  \lor  (p  \land  q)$

$=p  \lor  ( \lnot r  \land  s)$

$=(p  \lor   \lnot r)  \land  (p  \lor  s)$

### c
$=((p  \land   \lnot q)  \lor  ( \lnot r  \land  s)) \land ((r  \lor   \lnot s) \lor ( \lnot p  \lor  q))$

$=((p  \land   \lnot q)  \lor  ( \lnot r  \land  s))  \land  (r  \lor   \lnot s  \lor   \lnot p  \lor  q)$

$=(((p  \land   \lnot q)  \lor   \lnot r )  \land  ((p  \land   \lnot q)  \lor  s))  \land  (r  \lor   \lnot s  \lor   \lnot p  \lor  q)$

$=(p  \lor   \lnot r)  \land  ( \lnot q  \lor   \lnot r)  \land  (p  \lor  s)  \land  ( \lnot q  \lor  s)  \land  (r  \lor   \lnot s  \lor   \lnot p  \lor  q)$

## 3
### i
S: weather is Sunny 

C: today is colder then yesterday

$ \lnot S  \land  C$

CNF:

$ \lnot S  \land  C$


### ii
W: we will go Swimming

S: it is sunny

$W \rightarrow S$

CNF:

$ \lnot W  \lor  S$


### iii
W: we will go Swimming

C: we take a canoe trip

$ \lnot W \rightarrow C$

CNF:

$W  \lor  C$


### iv
C: we take a canoe trip

H: we are home by sunset

$C \rightarrow H$

CNF:

$ \lnot C  \lor  H$


### c 

- $ \lnot S  \land  C$

- $ \lnot W  \lor  S$

- $W  \lor  C$

- $ \lnot C  \lor  H$

$ \lnot S  \land  C +  \lnot W  \lor  S =  \lnot W  \land  C$

$ \lnot W  \land  C + W  \lor  C = C$

$ \lnot C  \lor  H + C = H$

$\Rightarrow$ We will be home by sunset

## 4
### a + b
#### Anna claims that Barbara is lying:

$( \lnot ℓ_a → ℓ_b)  \land  (ℓ_a →  \lnot ℓ_b)$

CNF:

$=(ℓ_a  \lor  ℓ_b)  \land  ( \lnot ℓ_a  \lor   \lnot ℓ_b)$

(Because this equals a xor statement, one can already see that Anna and Barbara cannot be telling the truth at the same time and one of them is lying)

#### Barbara claims that Chris is lying:

$( \lnot ℓ_b → ℓ_c)  \land  (ℓ_b →  \lnot ℓ_c)$

CNF:

$=(ℓ_b  \lor  ℓ_c)  \land  ( \lnot ℓ_b  \lor   \lnot ℓ_c)$

(Because ...)

#### Chris claims that Anna and Barbara are lying:

$( \lnot ℓ_c → (ℓ_a  \lor  ℓ_b))  \land  (ℓ_c → ( \lnot ℓ_a  \land   \lnot ℓ_b))$

CNF:

$=( \lnot ℓ_c  \lor   \lnot ℓ_a)  \land  ( \lnot ℓ_c  \lor   \lnot ℓ_b)  \land  (ℓ_c  \lor  ℓ_a  \lor  ℓ_b)$

### c

- $A =(ℓ_a  \lor  ℓ_b)  \land  ( \lnot ℓ_a  \lor   \lnot ℓ_b)$

- $B =(ℓ_b  \lor  ℓ_c)  \land  ( \lnot ℓ_b  \lor   \lnot ℓ_c)$

- $C =( \lnot ℓ_c  \lor   \lnot ℓ_a)  \land  ( \lnot ℓ_c  \lor   \lnot ℓ_b)  \land  (ℓ_c  \lor  ℓ_a  \lor  ℓ_b)$

<br>

$K_0 = B_0 + C_0 = (ℓ_b  \lor  ℓ_c) + ( \lnot ℓ_c  \lor   \lnot ℓ_a) =(ℓ_b  \lor   \lnot ℓ_a)$

$K_1 = K_0 + C_1 = ( \lnot ℓ_c  \lor   \lnot ℓ_a)$

$K_2 = K_1 + C_2 = ℓ_b$

$K_3 = K_2 + A_0 =  \lnot ℓ_a$

$K_4 = K_3 + A_1 = \bold{ℓ_b}$