# Exercise 3

## 1
#### a)

∅ 

#### b)

|  C   |
| ---- |
|  b   |

## 2

#### a)
π[Credits](σ[Title = "databases"]\(Lecture))

#### b)

π[SName]\(Student⋈Examination)

#### c)
π[SName]\(σ[Credits = 6]\(Lecture))

#### d)

ρ[SName -> Name]\(π[SName]\(Student)) U ρ[PName -> Name]\(π[PName]\(Professor))

## 3
#### a)

{s.Name | s ϵ Students ∧ s.MatrNr = 4711}

#### b)

{s.Name | s ϵ Students ∧ {∃e ϵ Examination : e.MatrNr = s.MatrNr}}

## 4
"glidedb"