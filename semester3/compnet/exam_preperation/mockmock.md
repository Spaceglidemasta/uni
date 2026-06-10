Start: A

A -> B  = 2
A -> C = 15
A -> D = 3
A -> E = 7

Queue: B, D, E, C

B -> E = 3: A -> E = 2 + 3 = 5

Queue: D, E, C

D -> E = 1: A -> E = 3 + 1 = 4
D -> C = 4: A -> C = 3 + 4 = 7
D -> G = 9: A -> G = 3 + 9 = 12
D -> F = 10: A -> F = 3 + 10 = 13

Queue: E, C, G, F

E -> F = 2: A -> F = 4 + 2 = 6

Queue: F, C, G

F -> G = 1: A -> G = 6 + 1 = 7

Queue: C, G

C -> G = 6

Queue: G

-> end

A -> B = 2 A 
A -> C = 7 D
A -> D = 3 A
A -> E = 4 D
A -> F = 6 E
A -> G = 7 F
 