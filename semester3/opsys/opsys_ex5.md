# Exercise 5

## 1

### 1

In Real Mode, only a maximum of 1MB can be addressed. This is then split up into lower and upper memory, with lower memory taking up 640kB, which can be used by the OS and applications. The rest, the 384kB upper memory, is reserved for the BIOS and device drivers.
When addressing memory in Real mode, the memory is divided into segments of eqal size, this beeing 64kB.
The addressing itself is implemented via segment and offset  (_Segment:Offset_). 

### 2 
The reason this doesnt work well with multithreading & asynchronous tasks, is that the memory is not protected or allocated in any way, making memory savety almost inpossible when running multiple tasks.

### 3, 4, 5
Protected mode was introduced later, leading to it beeing able to proccess more main memory, scaling with the numbers of buslines present in the arch..

Virtual Memory is beeing mapped to the real memory, while only beeing accessed by the task that created it. Therefore programs dont interact with the main memory itself, but with copies that only they can access. The Virtual Memory has its own address space, starting with 0.

Therefore swapping / loading data from the memory to the SSD / HDD is transparent for the User and the processes. 

### 6 
Mapping means assigning each element of a given domain, in this case the virtual memory, another or multiple other elements in another domain, in this case the main memory.
_See std::unorderered_map<obj1, obj2>(...)_

### 7
Swapping means swapping or loading memory from the SSD/HDD to the Main memory or vice versa. This is required when the main memory is not big enough. This way more data can be used then available in the RAM.

### 8
The Memory Management Unit (MMU)

### 9
The MMU translates Virtual addresses via the page table into the physical addresses on the main memory or SSD/HDD.

### 10
Only Internal Fragmentation. This is because if the needed memory for a process would be going outbound of the current last page, a new one is assigned. This way only there can only be unused memory left in the last used page.

### 11 & 13
- Protection Violation -> Protection Fault
- Accessing pages that dont exist in the page table -> Segmentation fault
- Trying to access a page that is not loaded into the Main memory and is still stuck on swap space

### 12 & 14
Depends on the fault:
- Protection Fault -> no permission -> throws Exception
- Segmentation Fault -> page doesnt exist -> throws Exception
- Page is valid but not in RAM -> tries to fix it by moving it into RAM


## 2
1. false
2. true
3. true. Any unused space in the partitionblock is a internal fragment
4. false
5. true
6. false: Internal fragmentation scales with the pagesize
7. true
8. true
9. false: Only protected mode yes, but not only paging: Also segmentation👍

## 3
### 1
OPT replaces the page that will not be swapped for the longest time in the future, which is impossible to implement, as you need to be able to look into the future.

### 2
... 

### 3

The key message of Laszlo Belady's anomaly is, that sometimes adding more memory (in this case pages) cannot always mean that performance is improved. Sometimes having more memory can cause more exceptions to happen.

### 4

nah, the first one is just gonna have less misses then the second one, even tho it has less pages.