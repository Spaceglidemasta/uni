# Exercise Sheet 8

## 1 Inter-Process Communication
### 1
When data is shared between multiple threads, the threads contain __critical sections__.
### 2
If the process' behavior depends on the order of multiple tasks, it is called a __race condition__.
### 3
The problem with these race conditions is, that if they are executed in the wrong order, that they can cause bugs.
<br>This can be avoided with proper synchronization.

## 2 Communication of Processes
### 1
- Certain tasks must be awaited by threads e.g. some threads may need to wait till another one is finished with a certain task.
- shared data can only be accessed by one thread at a time
### 2
The __shared memory table__ assigns threads to different parts of the shared memory, securing that only one thread my access one part of the data at a time.
### 3  
The shared memory segments and their contents are lost.
### 4
two.
### 5
the writing process is blocked
### 6
the reading process is blocked
### 7
Named and unnamed pipes:
- anonymous / unnamed pipes are used for related processes, like a child and parent process. When both processes end, the pipe is closed by the OS.
- named pipes can be used between any processes that know the path / name of the pipe. They will __not__ automatically be destroyed by the OS.
### 8
Connectionless sockets (UDP)
Connection-oriented sockets (TCP)
### 9
stream
### 10
memory
### 11
memory
### 12
stream
### 13
Shared memory segments
Sockets
### 14
Anonymous pipes
### 15
Sockets
(Message queues if you count DNS as one)
### 16
message queues
### 17
shared memory segemnts
## 3 Synchronization
### 1
The process is not frozen while awaiting the message
### 2
- Deadlock
- Starvation
### 3
Signaling specifies an order of execution, locking does not.
### 4
1. Circular wait
2. Hold and wait
3. No preemtion
4. Mutual excklusion
### 5
Availabe resource vector:
$$\begin{pmatrix}
8 - (2 + 3 + 0) & 6 - (2 + 1 + 1) & 7 - (0 + 0 + 1) & 5 - (0 + 4 + 1)
\end{pmatrix}
$$<br>
$$= \begin{pmatrix}
3 & 2 & 6 & 0
\end{pmatrix}$$

Process 1 and 3 are blocked, 2 is not.
<br>It finishes and deallocates its memory.

$$\text{Request matrix} = \begin{bmatrix}
3 & 2 & 4 & 5 \\
\_ & \_ & \_ & \_ \\
4 & 3 & 5 & 4
\end{bmatrix}$$

Available resource vector:
$$\begin{pmatrix}
6 & 3 & 6 & 4
\end{pmatrix}$$

Process 1 is blocked.<br>
Process 3 is not. It finishes and deallocates its memory.
$$\text{Request matrix} = \begin{bmatrix}
3 & 2 & 4 & 5 \\
\_ & \_ & \_ & \_ \\
\_ & \_ & \_ & \_ \\
\end{bmatrix}$$

Available resource vector:

$$\begin{pmatrix}
6 & 4 & 7 & 5
\end{pmatrix}$$

Process 1 finishes and deallocates its memory.

$\rarr$ __No deadlock occured.__
## 4 Cooperation of Processes
### 1 & 2
Semaphore is a concept, where threads are beeing organized by 2 operations.

This is initialized by creating a counter variable which starts at a given positive integer.

The first operation is __P__, which is also called "reduce"; Like the name states, this variables reduces, in this case the counter. If this counter hits 0, the process is blocked.

The second operation, __V__, immediately increments the counter by 1, unblocking a waiting process if one exists. 

It serves as a queue which organizes threads by the FIFO principle.

### 3
Locks just lock / unlock a thread, there is no concept of structure, lifetime or order of execution behind it.

Semaphores operate after the FIFO principle; Starvation is not possible, unlike with locks.
### 4
A semaphore init. with COUNT=1 to ensure that 2< processes cant access their critical sections simultaneously.
### 5
A mutex is the most simple lock.

lock() to lock a thread.

unlock() to unlock a thread.
### 6
binary
### 7
locked / unlocked

