# Exercises: Propositional Resolution

## 1
### a
$(¬p ∨ q) ∧ (r ∨ ¬s) ∧ (¬p ∨ ¬q)$

###### (Already NNF)

### b
$((¬p ∨ q) ∧ (r ∨ ¬s)) → ¬(¬p ∨ ¬q)$

$=((¬p ∨ q) ∧ (r ∨ ¬s)) → (p ∧ q)$

$=¬((¬p ∨ q) ∧ (r ∨ ¬s)) ∨ (p ∧ q)$

$=(¬(¬p ∨ q) ∨ ¬(r ∨ ¬s)) ∨ (p ∧ q)$

$=(p ∧ ¬q) ∨ (¬r ∧ s) ∨ (p ∧ q)$



### c

Note:

$A ↔ B = (A→B)∧(B→A) = (¬A∨B)∧(¬B∨A)$

This means:

$(¬p ∨ q) ↔ (¬r ∧ s)$

$=((¬p ∨ q) → (¬r ∧ s))∧((¬r ∧ s)→(¬p ∨ q))$

$=(¬(¬p ∨ q) ∨ (¬r ∧ s))∧(¬(¬r ∧ s)∨(¬p ∨ q))$

$=((p ∧ ¬q) ∨ (¬r ∧ s))∧((r ∨ ¬s)∨(¬p ∨ q))$

## 2
### a
$(¬p ∨ q) ∧ (r ∨ ¬s) ∧ (¬p ∨ ¬q)$´
###### (Already CNF)

### b
$(p ∧ ¬q) ∨ (¬r ∧ s) ∨ (p ∧ q)$

$=p ∨ (¬r ∧ s)$

$=(p ∨ ¬r) ∧ (p ∨ s)$

### c
$=((p ∧ ¬q) ∨ (¬r ∧ s))∧((r ∨ ¬s)∨(¬p ∨ q))$

$=((p ∧ ¬q) ∨ (¬r ∧ s)) ∧ (r ∨ ¬s ∨ ¬p ∨ q)$

$=(((p ∧ ¬q) ∨ ¬r ) ∧ ((p ∧ ¬q) ∨ s)) ∧ (r ∨ ¬s ∨ ¬p ∨ q)$

$=(p ∨ ¬r) ∧ (¬q ∨ ¬r) ∧ (p ∨ s) ∧ (¬q ∨ s) ∧ (r ∨ ¬s ∨ ¬p ∨ q)$

## 3
### i
S: weather is Sunny 

C: today is colder then yesterday

$¬S ∧ C$

CNF:

$¬S ∧ C$


### ii
W: we will go Swimming

S: it is sunny

$W \rightarrow S$

CNF:

$¬W ∨ S$


### iii
W: we will go Swimming

C: we take a canoe trip

$¬W \rightarrow C$

CNF:

$W ∨ C$


### iv
C: we take a canoe trip

H: we are home by sunset

$C \rightarrow H$

CNF:

$¬C ∨ H$


### c 

- $¬S ∧ C$

- $¬W ∨ S$

- $W ∨ C$

- $¬C ∨ H$

$¬S ∧ C + ¬W ∨ S = ¬W ∧ C$

$¬W ∧ C + W ∨ C = C$

$¬C ∨ H + C = H$

$\Rightarrow$ We will be home by sunset

## 4
### a + b
#### Anna claims that Barbara is lying:

$(¬ℓ_a → ℓ_b) ∧ (ℓ_a → ¬ℓ_b)$

CNF:

$=(ℓ_a ∨ ℓ_b) ∧ (¬ℓ_a ∨ ¬ℓ_b)$

(Because this equals a xor statement, one can already see that Anna and Barbara cannot be telling the truth at the same time and one of them is lying)

#### Barbara claims that Chris is lying:

$(¬ℓ_b → ℓ_c) ∧ (ℓ_b → ¬ℓ_c)$

CNF:

$=(ℓ_b ∨ ℓ_c) ∧ (¬ℓ_b ∨ ¬ℓ_c)$

(Because ...)

#### Chris claims that Anna and Barbara are lying:

$(¬ℓ_c → (ℓ_a ∨ ℓ_b)) ∧ (ℓ_c → (¬ℓ_a ∧ ¬ℓ_b))$

CNF:

$=(¬ℓ_c ∨ ¬ℓ_a) ∧ (¬ℓ_c ∨ ¬ℓ_b) ∧ (ℓ_c ∨ ℓ_a ∨ ℓ_b)$

### c

- $A =(ℓ_a ∨ ℓ_b) ∧ (¬ℓ_a ∨ ¬ℓ_b)$

- $B =(ℓ_b ∨ ℓ_c) ∧ (¬ℓ_b ∨ ¬ℓ_c)$

- $C =(¬ℓ_c ∨ ¬ℓ_a) ∧ (¬ℓ_c ∨ ¬ℓ_b) ∧ (ℓ_c ∨ ℓ_a ∨ ℓ_b)$

<br>

$K_0 = B_0 + C_0 = (ℓ_b ∨ ℓ_c) + (¬ℓ_c ∨ ¬ℓ_a) =(ℓ_b ∨ ¬ℓ_a)$

$K_1 = K_0 + C_1 = (¬ℓ_c ∨ ¬ℓ_a)$

$K_2 = K_1 + C_2 = ℓ_b$

$K_3 = K_2 + A_0 = ¬ℓ_a$

$K_4 = K_3 + A_1 = \bold{ℓ_b}$