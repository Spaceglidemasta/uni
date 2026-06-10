# Mock exam
## Q1
### a)
True
### b)
True:
UDP does not have any handshake, increasing the risk for package loss but decreasing unnecessary overhead.
### c) 
True
### d)
True:
Upper layers are abstractions of lower layers
### e)
Wrong:
This is the standart and will be the case for 99.9% of networks, but technically, it does not have to be this way
### f)
True?
### g)
Wrong
### h)
Wrong:
IP addresses are still used for regular networks like home networks and anything else that isnt a website
### i)
True
if the multicast group has only 1 reciever, yes
### j)
Wrong:
Most of the time distribution algorithms work with the whole network. Working with local data is only common in extremely big networks.
## Q2
$$\text{size}_{\text{Bitmap}} = 6144 \cdot 3456 \cdot 48 =  1019215872 $$

1,019,215,872 bits = 127,401,984 bytes

127,401,984 bytes = 124,416 kB

124,416 kB = 121.5 mB

121.5 mB = 0.11865234375 gB

0.11865234375 gB / (10 gB / s) = 0.011865234375 s

0.011865234375 s = 11.865234375 ms

### b)
The bandwith of a channel is the theoretical, maximum data flow the channel has. But because it is phisically impossible to transmit data trough a channel perfectly and because data loss / distortion (trivial), the actual transmitted data-speed, the _goodput_, is always lower then the actual bandwith.
### c)
The propagation is more relevant when sending big packages over small distances, the transmission delay is more important when sending any package over long distances.
### d)
small WLAN networks
### e)
big WLAN networks
## Q3
### a)
Tech / Protocol:    Ethernet (IEEE)
PDU:                Frame
function:           Framing / Mac adressing
### b)
Tech / Protocol:    UDP / TCP
PDU:                Segment / Datagram
function:           End to end connection, error detection
## Q4
### a)
1. yes
2. yes
3. yes
4. no, this is a private address
5. yes
6. yes
7. no, this address is for local networks only.

### b)
#### 1
IP Address:         11000001 01111000 11111010 01011010
Subnet:             11111111 11111111 11100000 00000000
Network Address:    11000001 01111000 11100000 00000000 = 193.120.224.0
First host address: 193.120.224.1
Last host address:  193.120.224.254
Broadcast:          193.120.224.255

#### 2
IP Address:         01010111 10110001 01101010 10100101
Subnet:             11111111 11111111 11111111 11000000
Network address:    01010111 10110001 01101010 10000000 = 87.177.106.128
First host address: 87.177.106.129
Last host address:  87.177.106.190
Broadcast:          87.177.106.191

## Q5
### a)
Message 1: 10.0.0.4:444555 -> 193.104.220.7:433
Message 2: 194.95.83.45:56478 -> 193.104.220.7:443
Message 3: 193.104.220.7:443 -> 194.95.83.45:56478
Message 4: 193.104.220.7:443 -> 10.0.0.4:444555
### b)
145.34.104.0
145.34.104.0
-> no

## Q6
### a)
| Msg | ACK | SYN | FIN | Payload len | Seq  | Ack  |
| --- | --- | --- | --- | ----------- | ---- | ---- |
| 1   | 0   | 1   | 0   | 0           | 3247 | 0    |
| 2   | 1   | 1   | 0   | 0           | 7    | 3248 |
| 3   | 1   | 0   | 0   | 0           | 3248 | 8    |
### b)
| Msg | ACK | SYN | FIN | Payload len | Seq | Ack |
| --- | --- | --- | --- | ----------- | --- | --- |
| 4   | 0   | 0   | 0   | 130         | 50  | 500 |
| 5   | 1   | 0   | 0   | 200         | 500 | 180 |
| 6   | 1   | 0   | 0   | 130         | 180 | 700 |
| 7   | 1   | 0   | 0   | 20          | 700 | 310 |
### c)
| Msg | ACK | SYN | FIN | Payload len | Seq  | Ack  |
| --- | --- | --- | --- | ----------- | ---- | ---- |
| 8   | 0   | 0   | 1   | 0           | 1    | 2342 |
| 9   | 1   | 0   | 0   | 0           | 2342 | 2    |
| 10  | 0   | 0   | 1   | 0           | 2342 | 2    |
| 11  | 1   | 0   | 0   | 0           | 2    | 2343 |

## 8
### a)
UDP is send & forget. You send a package to your target without getting confirmation if the reciever ever recieved the package. This causes less overhead, but also more package loss.
To send something with TCP, you first need to setup a connection via a handshake. After that, the reciever of each package needs to acknowladge each package with an acknowladgement message. The connection is closed once both parties confirm closage. The connection is bidirectional.
### b)
The seq number in an TCP segment specifies a control number, which the reciever of the package sends back in the Ack segment, modified in respect to the current action e.g. handshake, transmission or termination.
### c)
The ACK number is a single bit which is 1 when acknowladging handshakes and connection terminations.
### d)
The silly window problem occurs when to many small packages are sent into a network, which causes too much pressure on the network because of overhead. The solution / avoidance to this is waiting till enough data-to-be-send has accumilated, upon which this data is sent together in packet, decreasing overhead. Same principle as flushing a terminal (or a toilet).  
### e)
one window is used to determine the possible bandwith of the network, the other one for the bandwith of the reciever. The minimum of both is the maximum the sender will send.
## Q9
### a)
The MAC address is burned into every ethernet port by the manufactorer.
### b)
The IP address is usually assigned dynamically to every host in a network by the router. It can also be assigned staticly by the host itself.
### c)
The MAC address is used for communication inside the network, the IP address is required for communication over the internet. But because the Internet only knowns the address of the router, every host inside a network needs to go trough the router first. This means that the MAC address is used to send the data from the host to the router / reversed, and then the IP address is used to send the data from the router to the desired address in the internet. Each network has a table mapping each MAC address to the corresponding local IP address.
### d)
nothing special. The ARP table updates my MAC address and everything works fine.
### e)
nothing special. But this time my computer loses its internet connection, if I got past the point that my pc actually allows me to to this.

