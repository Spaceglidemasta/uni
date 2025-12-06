# Exercise 4

## 1 Error Control

### 1

$E[Frames] = 16 ⋅ \frac{1}{0.75^{16}}$

$≈1596.39$ on average 

### 2 & 3

$E[Frames] = 16 ⋅ \frac{16 ⋅ 4}{3} ≈ 21.333$

### 4

detect: 1
correct: 0

$d = 2k + 1 ; d = 2$

$2 = 2k + 1$

$=> k = 0.5$

#### For example:
0011 0000 could not be corrected, as it could be 
$w5$ or $w6$

### 5

The CRC needs to be appended at the end, because neither the sender nor the reciever know the CRC until the whole message has been processed.

### 6
All of them, because the CRC16-CCITT has a hamming distance of 2, and therefore an error correction of 1 => When atleast one bit changes, the CRC checksum is different. (?)

## 2 Error Detection - CRC

### 1

8-Bit payload => 7 Bits are beeing appended.

Message: 11010011 0000000
```
110100110000000 ^
100101
 100011
 100101
    110100
    100101
     100010
     100101
        111000
        100101
         111010
         100101
         ------
         011111
```
Final Frame = 11010011 011111

### 2
```
1101001110100 ^
100101
 100011
 100101
    110110
    100101
     100111
     100101
         1000
         100101
         0001 => No
```

### 3
```
1101001111100 ^
100101
 100011
 100101
    110111
    100101
     100101
     100101
          0 => Yes
```

## 3 Address Resolution Protocol
### 1
The ARP - Adress Resolution Protocol is used to determine the MAC address of a device via its IPv4 address.

It works by sending a broadcast containing the IPv4 Address of the target device. Each device compares this to its own IPv4 Address; If it matches, the device sends an ARP response via unicast containing its MAC address back to the sender.

### 2
- ARP only has one job: Mapping a MAC address to a IPv4 Address. NDP does alot more.
- ARP uses Broadcast instead of multicast like NDP, causing extreme security riscs and more network load.
- NDP uses SLAAC to determine an IPv6 address for you
- NDP can find routers on its own
- ARP is used for IPv4 and more, NDP is specifically designed for IPv6. (ARP was also designed for IPv4, but can be used for a lot of other things, unlike NDP)

### 3
MAC spoofing can be used to be "the man in the middle", reading out data unnoticed "sniffing", alter it or deny it completely (DOS Attack). This is done by sending a fake ARP message to the Device, claiming to be a trusted device (e.g. the router).  

### 4
ARP (and NDP) have a cache which maps recently contacted IPv4 addresses to their respective MAC addresses. Works kinda like a page table, with the difference that when an address doesnt exist in the cache, it can still be relevant, unlike a page in the pagetable, that is not used / said to not even exist when not shown in the page table. 

## 4 IPv4 Addressing in the Network Layer
IP Address: 151.175.31.100<br>
Subnet mask: 255.255.254.0<br>
Network address: 151.175.30.000<br>
First Host address: 151.175.30.001<br>
Last Host address: 151.175.31.254<br>
Broadcast address: 151.175.31.255<br>


IP Address: 151.175.31.100<br>
Subnet mask: 255.255.255.240<br>
Network address: 151.175.31.96<br>
First host address: 151.175.31.97<br>
Last host address: 151.175.31.110<br>
Broadcast address: 151.175.31.111<br>

IP Address: 151.175.31.100<br>
Subnet mask: 255.255.255.128<br>
Network address: 151.175.31.0<br>
First host address: 151.175.31.001<br>
Last host address: 151.175.31.126<br>
Broadcast address: 151.175.31.127<br>

## 5 Address Types and Spaces
### 1
1. 10
2. 172.16
3. 192.168

### 2
#### IPv4
169.254.0.0/16
#### IPv6
fe80::/10

### 3
- 224.1.2.3
- 234.23.23.23

### 4
It cannot.

### 5
FF02::1

### 6
unicast
-> Private and direct Communication

### 7
multicast -> reach all stations in the local network

## 6 Network Address Translation
|Message #  | Source IP | Destination IP 
|----       | ---       | ---
| 1         | 192.168.178.115:49160         | 65.108.193.50:443
| 2         | 77.182.8.252:60789         | 65.108.193.50:443
| 3         | 65.108.193.50:443        | 77.182.8.252:60789
| 4         | 65.108.193.50:443         | 192.168.178.115:57463 

## 7 IPv6 Address Representation
### 1
1080:0000:0000:0000:0007:0700:0003:316b: <br>
1080::7:700:3:316b

2001:0db8:0000:0000:f065:00ff:0000:03ec: <br>
2001:db8::f065:ff:0:3ec

2001:0db8:3c4d:0016:0000:0000:2a3f:2a4d: <br>
2001:db8:3c4d:16::2a3f:2a4d

2001:0c60:f0a1:0000:0000:0000:0000:0001: <br>
2001:c60:f0a1::1

2111:00ab:0000:0004:0000:0000:0000:1234: <br>
2111:ab:0:4::1234

### 2
2001::2:0:0:1: <br>
2001:0000:0000:0000:0002:0000:0000:0001

2001:db8:0:c::1c: <br>
2001:0db8:0000:000c:0000:0000:0000:001c

1080::9956:0:0:234: <br>
1080:0000:0000:0000:9956:0000:0000:0234

2001:638:208:ef34::91ff:0:5424 <br>
2001:0638:0208:ef34:0000:91ff:0000:5424

2001:0:85a4::4a1e:370:7112 <br>
2001:0000:85a4:0000:0000:4a1e:0370:7112

## 8 "Do Some research"
## 9 Lab penis