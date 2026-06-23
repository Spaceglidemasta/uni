###### Luca De Simone 1592157
# Homework 7
## Exercise 1 Rate Monotonic Scheduling
### 1 Taskset: { T1 (7, 24); T2 (1, 8); T3 (4, 14); T4 (3, 15) }
![](./screenshots/1_1.PNG)
### 2 Taskset: { T1 (6, 20); T2 (3, 12); T3 (4, 10) }
![](./screenshots/1_2.PNG)
### 3 Taskset: { T1 (7, 20); T2 (3, 12); T3 (4, 10) }
![](./screenshots/1_3.PNG)
### 4 Load
#### 1

$$T_1 = \frac{7}{24}$$

$$T_2 = \frac{1}{8}$$

$$T_3 = \frac{4}{14}$$

$$T_4 = \frac{3}{15}$$

$$T_* = \frac{3}{15} + \frac{4}{14} + \frac{1}{8} + \frac{7}{24} = \frac{379}{420} \approx{0.9024}$$

#### 2

$$T_1 = \frac{6}{20} = \frac{3}{10}$$

$$T_2 = \frac{3}{12} = \frac{1}{4}$$

$$T_3 = \frac{4}{10} = \frac{2}{5}$$

$$T_* = \frac{3}{10} + \frac{1}{4} + \frac{2}{5}
= \frac{6}{20} + \frac{5}{20} + \frac{8}{20}
= \frac{19}{20}
= 0.95$$

#### 3

$$T_1 = \frac{7}{20}$$

$$T_2 = \frac{3}{12} = \frac{1}{4}$$

$$T_3 = \frac{4}{10} = \frac{2}{5}$$

$$T_* = \frac{7}{20} + \frac{1}{4} + \frac{2}{5}
= \frac{7}{20} + \frac{5}{20} + \frac{8}{20}
= \frac{20}{20}
= 1.0$$

### 5 Schedulability tests
#### 1

$$U \leq n(2^{1/n} - 1)$$

$$0.9024 \leq 4 * (2^{1/4} - 1)$$

$$0.9024 \leq 0.7568$$

$\Rightarrow$ Maybe not schedulable

#### 2

$$U \leq n(2^{1/n} - 1)$$

$$0.95 \leq 3 * (2^{1/3} - 1)$$

$$0.95 \leq 0.7797631496846196$$

$\Rightarrow$ Maybe not schedulable

#### 3

$$U \leq n(2^{1/n} - 1)$$

$$1 \leq 3 * (2^{1/3} - 1)$$

$$1 \leq 0.7797631496846196$$

$\Rightarrow$ Maybe not schedulable

## Exercise 2 Earliest Deadline First (EDF)
### Taskset: { T1 (1, 8); T2 (6, 22); T3 (3, 15); T4(4, 20)}
![](./screenshots/2_1.PNG)
### Taskset: { T1 (2, 10); T2 (4, 15); T3 (5, 12)}
![](./screenshots/2_2.PNG)
### Taskset: { T1 (5, 12); T2 (2, 10); T3 (4, 15)}
![](./screenshots/2_3.PNG)

### Schedulability tests

#### Taskset 1: 

$$T^1 = \frac{1}{8} = 0.125$$

$$T^2 = \frac{6}{22} = 0.2727272727$$

$$T^3 = \frac{3}{15} = 0.2$$

$$T^4 = \frac{4}{20} = 0.2$$

$$\frac{1}{8} + \frac{6}{22} + \frac{3}{15} + \frac{4}{20} = \frac{351}{440} \approx 0.7977$$
#### Taskset 2: 

$$T^1 = \frac{2}{10} = 0.2$$

$$T^2 = \frac{4}{15} = 0.2666666667$$

$$T^3 = \frac{5}{12} = 0.4166666667$$

$$\frac{2}{10} + \frac{4}{15} + \frac{5}{12} = \frac{53}{60} \approx 0.8833333333$$
#### Taskset 3: 

$$T^1 = \frac{5}{12} = 0.4166666667$$

$$T^2 = \frac{2}{10} = 0.2$$

$$T^3 = \frac{4}{15} = 0.2666666667$$

$$\frac{5}{12} + \frac{2}{10} + \frac{4}{10} = \frac{53}{60} \approx 0.8833333333$$

### RMS-like tests

####  Taskset 1

$$ 0.7977 \leq 4(2^{1/4} -1)$$

$$ 0.7977 \leq 0.7568$$

$\Rightarrow$ Maybe not schedulable

####  Taskset 2

$$0.8833 \leq 3(2^{1/3} -1)$$

$$0.8833 \leq 0.7797$$

$\Rightarrow$ Maybe not schedulable

####  Taskset 3

$$ 0.8833 \leq 3(2^{1/3} -1)$$


$$ 0.8833 \leq 0.7797$$

$\Rightarrow$ Maybe not schedulable