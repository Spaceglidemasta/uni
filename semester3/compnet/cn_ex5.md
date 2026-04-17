# Exercise 5
## 1 Forwarding and Path Calculation
### 1 
A system that interacts and reacts upon external factors, with minimal or no direct human intervention

### 2 & 3
#### Distance-Vector-Protocol
Distance Vector Protocols like Bellman-Ford only
share information about the neighbours of each respective node. That's why BF is using a Stack instead of a queue.

#### Link-State-Protocol
Link State Protocols like Dijkstra share the information
about the whole topology with each node. This is why
Dijkstra uses a queues instead of a stack

### 4
Inter-AS, as it connects multiple AS together.

### 5
Path Vector Protocol

### 6
Intra AS Routing

### 7
Link State Protocol

### 8
Intra AS Routing

### 9
Link State Protocol

### 10 & 11
Decisions resolve way faster, because only a small part of the network as to be accounted for -> less memory needed. On the other hand, this may lead into dead-ends,which may increase the time cost in the end. RIP is also only really useful in small networks, as its maximum hop count is 15.

### 12
- Advantages: OSPF overlooks the whole topology, resulting in a very efficient and fast Path to the target. This also means that when a node changes, the path can be adapted very quickly.
- Disadvantages: The memory needed scales with the network, leading to high CPU and memory demands. OSPF also does not support Policies. Its configuration and troubleshooting are also very complex.

## 2 Inter-Networking

### 1

#### Sender 1

- Subnet ID of sender: 201.20.222.0
- Subnet ID of sender: 201.20.222.16
- The package leaves the subnet

#### Sender 2
- Subnet ID of sender: 15.192.0.0
- Subnet ID of sender: 15.192.0.0
- The package does not leave the subnet

### 2
1. wlan1
2. eth3 X -> bad gateway -> standart 0.0.0.0 -> eth0.
Explanation: ...17 does not fit into the subnetmask of 192.168.42.0 (255.255.255.240). It contains 1 bit too much at pos 4
3. eth3
4. eth1
5. eth2. It fits in both
255.252.0.0 and 255.248.0.0, but 255.248.0.0 is more 
specific, as it has more network bits<br> -> eth2
6. doesnt fit anywere -> UG -> eth0
7. 172.17.8.15 = UH -> eth2
8. works for wlan0 and eth2, but eth2 is more specific with network addresses -> eth2
9. Std gateway -> eth0

## 3 Bellman-Ford Algorithm
#### Step 2 additions:
    A -> C = 1
    A -> B = 1
    
    B -> A = 1
    B -> D = 1
    B -> E = 1

    C -> D = 1
    C -> A = 1

    D -> B = 1
    D -> C = 1
    D -> F = 1

    E -> B = 1

    F -> D = 1

#### Step 3 additions

    A -> D = 2
    A -> E = 2
    
    B -> C = 2
    B -> F = 2
    B -> C = 2 => no change

    C -> B = 2
    C -> F = 2
    C -> B = 2 => no change

    D -> A = 2
    D -> E = 2
    D -> A = 2 => no change

    E -> D = 2
    E -> A = 2

    F -> B = 2
    F -> C = 2

#### Step 4 additions

    A -> F = 3
    A -> F = 3 => no change

    C -> E = 3
    C -> E = 3 => no change

    E -> C = 3
    E -> C = 3 => no change
    E -> F = 3

    F -> A = 3
    F -> A = 3 => no change
    F -> E = 3

## 4 Dijkstra’s Algorithm

|  A   |  B   |   C  |   D  |  E    |  F    |
| ---- | ---- | ---- | ---- | ----  | ----  |
| A:0  | A:2  | A:2  |      |       |       |
| B:2  | C:/  | ...  |      |       |       |
| C:2  | D:/  |      |      |       |       |
| D:3  | E:1  |      |      |       |       |
| E:/  | F:100|      |      |       |       |
| F:/  | B:0  |      |      |       |       |

