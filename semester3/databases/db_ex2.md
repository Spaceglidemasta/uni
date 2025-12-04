# Exercise Sheet 1

## 1

#### a)

<table>
<tr>
<th> σ[A=d](R) </th><th> π[A](σ[B=b](R)) </th><th> R x S </th>
</tr>
<td>

|   A   |   B   |
| ---- | ---- |
|   d   |   e   |

</td>
<td>

|   A   |
| ---- |
|   a   |
|   d   |


</td>
<td>

| A | B | B' | C |
| - | - | - | - |
| a | b | b | c |
| a | b | d | a |
| a | b | c | d |
| c | b | b | c |
| c | b | d | a |
| c | b | c | d |
| d | e | b | c |
| d | e | d | a |
| d | e | c | d |


</td></tr>
<tr>
<th> σ[A=C](R x S) </th><th> R ⋈ S  </th><th> π[A](R ⋈ S) </th>
</tr>
<tr>
<td>

| A | B | B' | C |
| - | - | - | - |
| a | b | d | a |
| c | b | b | c |
| d | e | c | d |

</td>
<td>

|   A  |   B  |   C  |
| ---- | ---- | ---- |
|  a   |  b   |   c  |


</td>
<td>

|   A  |
| ---- | 
|   a  | 


</td></tr>
<tr>
<tr>
<th> π[A](R) ⋈ S </th><th> R ⋈ T1  </th><th> R ⋈ S1 </th>
</tr>

<td>

|   A  |   B  |   C  |
| ---- | ---- | ---- |
|  a   |  b   |   c  |
|  a   |  f   |   a  |
|  a   |  b   |   d  |
|  c   |  b   |   c  |
|  c   |  f   |   a  |
|  c   |  b   |   d  |
|  d   |  b   |   c  |
|  d   |  f   |   a  |
|  d   |  b   |   d  |

</td>
<td>

|   A  |   B  |   C  |
| ---- | ---- | ---- |
|  a   |  b   |   b  |
|  a   |  b   |   c  |
|  c   |  b   |   b  |
|  c   |  b   |   c  |
|  d   |  e   |   b  |
|  d   |  e   |   c  |


</td>
<td>

|   A  |  B   |
| ---- | ---- |
|   d  |  e   |


</td></tr>
<tr>
<tr>
<th> R ⋈[R.B < C] ​S </th><th> R ⟗ S  </th><th> R ⋃ S1 </th>
</tr>
<td>

| A | B | B'| C |
| - | - | - | - |
| a | b | b | c |
| c | b | b | c |
| a | b | b | d |
| c | b | b | d |

</td>
<td>


|   A  |   B  |   C  |
| ---- | ---- | ---- |
|  a   |  b   |   c  |
|  a   |  b   |   d  |
|  c   |  b   |   c  |
|  c   |  b   |   d  |
|  d   |  e   |   -  |
|  -   |  f   |   a  |



</td>
<td>

|  A   |  B   |
| ---- | ---- |
|  a   |  b   |
|  b   |  a   |
|  c   |  b   |
|  d   |  e   |
|  c   |  d   |

</td></tr>
<tr>
<tr>
<th> R \ S1  </th>
</tr>
<td>

|  A   |  B   |
| ---- | ---- |
|  a   |  b   |
|  c   |  b   |

</td>
</tr>
</table>

## 2

###  a)
#### R:

| MatrNr | SName | Birthday | Semester |
| - | - | - | - |
| ... | ... | ... | ... |

Query -> π[SName, Semester](σ[MatrNr = 4711]\(R))