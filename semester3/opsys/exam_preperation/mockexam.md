# Mock Exam 26012026

## 1

### a)
Wrong:
Most OS like linux or MacOS are not entirely reliant on micro-kernel

### b)
True:
Sometimes the multitasking overhead like forking the program and managing synchornization can cause simple programs to taker longer.

### c)
True:
A fork bomb creates a lot of child processes, killing systems with not much memory and without proper protection.

### d)
True:
It is very typical for an OS to implement multiple scheduling algorithms.

### e)
True:
This is a topology, as mutexes are binary semaphores.

### f)
False:
The occurrence of interrupts makes debugging more difficult

### g)
True:
Every x86 compatible CPU needs to have backwards compatability and therefore starts in Real Mode, like the old CPUs did.

### h)
Wrong:
The OSI reference model describes network transmission layers

### i)
Wrong:
Race Conditions can happen everywhere where things can be done in a wrong order.

### j)
Wrong:
The FAT table of a VFAT system has a fixed size.

## 2
### a)
pwd
### b)
cat
### c)
crontab -e
### d)
sed
### e)
head
### f)
ls
### g)
sort
### h)
zip
### i)
rm / rmdir
### j)
echo
### k)
ln
### l)
chmod

## 3
### a)
Because the OPT needs to look into the future, which will stay impossible until the birth of Dr. Emmett Brown
### b)
Advantage: Smaller Page Table
Disadvantage: More internal Fragmentation
### c)
If the requested page is outside of memory but inside the disk space, the space is swapped. If the address is completely out of bounds, the system interrupts the program.
### d)
Negativly. The power of this is dependent on wether the requested page is inside memory, which can be solved fast, or on the disk (HDD / SSD) which can take up to * 100.000 as long.
### e)
```c
int main(void){
    int* px = NULL;
    int x = *px; // <- here
}
```
## 4
### a)
The system stores the contex of processes in the Process Control Block (PCB)
### b)
Call parameters and return addresses of functions
### c)
1. If they are identical / related
2. They need the roughly the same size of data, resulting in them having the same number of pages allocated to them.
### d)
The nice level of a process determines the priority it has towards other processes in the system.
### e)
Scheduler
### f)
This forks the process, creating a child process which is the a copy of the process fork was called in.
### g)
exec replaces the process it was called in with a new proces specified in the system call
### h)
The program is the instructions a process is working trough. A process basically gives the program a name and other data, so the system can work with it better (or even at all)
## 5
### a)
busy waiting may yield a better performance then signal and wait when the waiting intervals of the busy waiting are very small.
### b)
1
### c)
2
### d)
processes may starve or take too long to execute
### e)
2
### f)
the read is blocked
### g)
named and unnamed / anonymous pipes
### h)
$S_a$ is beeing closed by the OS 
## 6
### a)
A user mode process wants to use kernel level services
### b)
When the system call is called, triggering a software interrupt, upon which the CPU switches into Kernel Mode, upon which the CPU executes the given task, switching back to user mode when its done.
### c)
The interrupt is delayed until the ISR is done with its current interrupt.
### d)
Interrupts allow the CPU to respond quickly and can be used for debugging purposes, but too frequent interrupts can cause overhead because of the ISR. In case of exceptions an interrupt may also terminate a process.
## 7
### a)
~/home/linus/mono.c
### b)
../../bin/dash
### c)
1. ~/usr/bin/zsh
2. ./bin/zsh
### d)
~/media/usb/src/password_generator/gen.cpp
### e)
../password_generator/gen.cpp
### f)
ln ~/bin/bash ~/usr/bin/binhl
### g)
mp3
### h)
1, the name is shorter then 8 + 3 chars
### i)
2, the name is longer then 8 + 3 chars
### j)
in the Directory Entry of the file
### k)
in the inode of the file
### l)
The file table / FCB / Inode points to the actual data on the disk
### m)
The FCB adds more p
## 9
### a)
Process starvation
### b)
To fork them, creating new child processes upon which programs can be executed
### c)

| Execution Order | Rt $P_A$ | Rt $P_B$ | Avg Rt | Wt $P_A$ | Wt $P_B$ | avg wt |
| --------------- | -------- | -------- | ------ | -------- | -------- | ------ |
| $P_A$, $P_B$    | 4ms      | 30ms     | 17ms   | 0ms      | 4ms      | 2ms    |
| $P_B$, $P_A$    | 30ms     | 26ms     | 28ms   | 26ms     | 0ms      | 13ms   |

### d)
The Execution Order $P_A \rightarrow P_B$ yields much better results.

## 10
### a)
script1.sh:<br>
/home/user/work/sinodes.txt
    it contains the content of inodes.txt, sorted.

script2.sh:<br>
/home/user/work/inodes.txt
    it contains the content of home/*, listed with ls, with the index of each file / dir at the start of the line.

### b)

Yes. script1.sh needs the file inodes.txt, so as long as there isnt such a file already present, script1.sh will always
terminate after script2.sh.

### c)
The concept present in those lines is busy waiting, which is the opposite of signal & wait. It permanently checks for the existence of inodes.txt, only exiting the while loop when its present.

### d)
Signal and wait would be more efficient. In this case this would be implemented by just fusing both files together, making any waiting redundant.

### e)
THis would append the content of \${INPUT} to \${OUTPUT}, if its present, instead of overwriting it completely regardless of existence.

### f)
This would replace the content of \${TMP} with the line in each iteration, resulting in TMP only containing the last ls call at the end of the loop.

## 11
Free Resource Vector:
$$
\begin{pmatrix} 1 & 1 & 2 & 2 & 3 & 2 \end{pmatrix}
$$

Process 1 executes and frees all its resrouces.

Current Allocation Matrix:
$$
\begin{bmatrix} 
\_ & \_ & \_ & \_ & \_ & \_ \\  
 2 &  1 &  2 &  0 &  0 &  3 \\ 
 1 &  3 &  2 &  1 &  0 &  1 \\  
 3 &  1 &  0 &  1 &  1 &  1
\end{bmatrix}
$$

Free Resource Vector:
$$
\begin{pmatrix} 3 & 1 & 4 & 5 & 5 & 2 \end{pmatrix}
$$

Process 2 & 3 are blocked because of missing resources.

Process 4 executes and frees all resources.

Free Resource Vector:
$$
\begin{pmatrix} 6 & 2 & 4 & 6 & 6 & 3 \end{pmatrix}
$$

Current Allocation Matrix:
$$
\begin{bmatrix} 
\_ & \_ & \_ & \_ & \_ & \_ \\  
 2 &  1 &  2 &  0 &  0 &  3 \\ 
 1 &  3 &  2 &  1 &  0 &  1 \\  
\_ & \_ & \_ & \_ & \_ & \_
\end{bmatrix}
$$

Process 2 runs and frees all resources.

...

Process 3 runs and frees all resources.

All processes executed correctly. __No deadlock occured.__