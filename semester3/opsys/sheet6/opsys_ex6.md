# Exercise 6
## 1 Processes
### 1
- User Context
- Hardware Context
- Software Context

### 2
User Context

### 3
The PCB does not store all context about the process, because some information needs to be retrieved with very high speed.

### 4
- thread stack pointer
- thread status
- thread priority
- process id
- set flags
- run queue entry
- wait data
- message waiters
- message queue
- message array
- thread stack start address
- thread name
- thread stack size

### 5
The dispatcher assigns a task from the queue to the CPU, carrieing out the state transitions.

### 6
The scheduler decides on the order of the queue using a scheduling algorithm

### 7
Queue & CPU<br>
dispatch & resign the CPU

### 8
No, because it assumes that every process is ready at any time. In practices, processes sleep or wait for external signals like user input.

### 9
Right-to-left & Top-to-bottom

Suspended, blocked, ready, running, new, exit

### 10
listing out all processes, and mapping them to their respective PCB, which contains their context

### 11
?

### 12
The only way on POSIX to create a new process.

It forks the process it was beeing called in, creating an exact copy of it. The calling process is called the parent process, and the new one the child process.

### 13
The exec() system call overwrites the PID of a process with another one.

This together with fork() is the core of creating a new process: Fork it with fork(), and then overwrite it with exec()

### 14
#### Process forking
1. fork()

#### Process chaining
1. exec()

#### Process creation
1. fork()
2. exec()

### 15
| #     | PP    | CP
| -     | -     | -
| PPID  | 72    | 75
| PID   | 75    | 198
| UID   | 18    | 18
| fork  | 198   | 0

### 16
init is the parent of a all processes. Like a blueprint from wrich every process is created via fork() and exec().
Like Seth on TempleOS.

### 17
Only the PID

### 18
it gets init as the new parent process

### 19
program code and constants, like in mips (and most asm [i think])

### 20
Dynamically allocated data during runtime

### 21
temporary data, that is needed during runtime, like function calls and local variables

## 2 Process States
```C

```

## 3 Forking Processes
```C

```