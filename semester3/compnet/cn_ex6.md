# Exercise 6
## 1 Applications and Transport Layer Protocols
### 1
- TCP
- UDP
- QUIC / TCP
- UDP
- QUIC / TCP
- UDP
- UDP if live, TCP / QUIC if on-demand

### 2
Because devices in IoT networks dont have much Memory and can therefore be easier overwhelmed by the big headers of TCP. 

## 2 TCP and UDP
### 1
The difference between UDP and TCP primarily lies in speed and data-completeness, with TCP having more overhead in order to ensure a successfull connection with minimal data loss, while UDP just sends of packages rawly, which leads to less latency but has the risc of losing packages without knowing it.
### 2
- Messaging
- File Download
### 3
- Live Streaming
- Synchronization
### 4
A socket consists of an IP address and a port. It can transfare data to that IP:Port with various TLS protocols. Data that is written into that socket is automatically send to the IP:Port of that socket via the TLS of the socket. It abstracts the need to to the sending manually.
### 5 & 6
the Seq number specifies the number the sender expects the reciever to awsner with as the Ack, added with the size of the package.
If seq = 1000 & package size = 500 bytes, Ack = 1500
### 7
The __silly window syndrome__ is a problem where a large amount of segments is beeing sent, with the outcome beeing too much overhead.
### 8
There are multiple ways to avoid this. One, is making the windows size dynamic e.g. sending an exponentially growing amount of bytes into the network until the timeout expires, halving the amount of bytes sent in the process and switchung into a linear mode, where, incrementally, one / two / three byte(s) is(are) being sent one after the other, until the threshold is reached / a timeout accures. At this point, the sender knows the window size and can send multiple segments at once.  
### 9
- Network capacity
- Reciever capacity
### 10
One window is the advertised size of the reciever, and one window is the determined window size of the network from the sender. The minimum of both is the maximum the sender can send.
### 11
The beginning of the process described in ##8, as exponential functions start slowly.

## 3 TCP Connections
### 1
| Message | ACK | SYN | FIN | Payload legnth | Seq number | ACK nubmer |
| ------- | --- | --- | --- | -------------- | ---------- | ---------- |
| 1       | 0   | 1   | 0   | 0              | 500        | 0          |
| 2       | 1   | 1   | 0   | 0              | 1000       | 501        |
| 3       | 1   | 0   | 0   | 0              | 501        | 1001       |
### 2
| Message | ACK | SYN | FIN | Payload legnth | Seq number | ACK nubmer |
| ------- | --- | --- | --- | -------------- | ---------- | ---------- |
| 4       | 0   | 0   | 0   | 50             | 501        | 1001       |
| 5       | 1   | 0   | 0   | 0              | 1001       | 551        |
| 6       | 0   | 0   | 0   | 100            | 551        | 1001       |
| 7       | 1   | 0   | 0   | 0              | 1001       | 651        |
### 3
| Message | ACK | SYN | FIN | Payload legnth | Seq number | ACK nubmer |
| ------- | --- | --- | --- | -------------- | ---------- | ---------- |
| 8       | 0   | 0   | 1   | 0              | 2000       | 3000       |
| 9       | 1   | 0   | 0   | 0              | 3000       | 2001       |
| 10      | 0   | 0   | 1   | 0              | 3000       | 2001       |
| 11      | 1   | 0   | 0   | 0              | 2001       | 3001       |
## 4 Transmission Control Protocol
### 1

$10 \cdot ⌈\log_2(\frac{24}{2})⌉ = 40\,\mathrm{ms}$ 

### 2
Fast recov. not used / Timeout -> complete reset

$(2\,\mathrm{kB})^4 = 16\,\mathrm{kB}$

### 3

$RTT = 10\,\mathrm{ms} \cdot 2$

$\rarr \text{Troughput}_{max} = \frac{\text{Windowsize}}{RTT}$

$\rarr  \text{Troughput}_{max} = \frac{65,535\,\mathrm{bytes}}{2 \cdot 10\,\mathrm{ms}}$

$\rarr \text{Troughput}_{max} = 26.2\,\mathrm{Mb/s}$

## 5 Header and Payload

IP header: 20 bytes<br>
TCP header: 20 bytes

Payload + both headers = 80 bytes

$\frac{40\,\mathrm{bytes}}{80\,\mathrm{bytes}} = 50\%$

## 6 TCP Congestion Control
### 1 & 2

Described [here](#8)

### 3
slow-start: $x \in [1:12]$<br>
congestion avoidance phase: $x \in [12:]$

### 4 & 5
Fast retransmit & recovery work together.

When the reciever notices a missing package in the transmission, instead of timing out, it sends the last successfull ACK __3 times__. 

The sender noticices this and resends the lost package (fast retransmit) and halves the current pace / cwnd (fast recovery), switching to the congestion avoidance phase / linear mode.

### 6
The aggressive exponential increase at the beginning is used to quickly surpass the treshhold of the network. Once the timeout / 3 identical ACKS occur, dropping to half of the cwnd brings the cwnd close to the actual treshold. The linear mode / congestion avoidance phase is then used to go even closer to the threshold. This combination allows the sender to find the threshhold quick and without exhausting the reciever for too long.

### 7
Sending multiple (thousand / million) SYN requests without awnsering to the ACKs, using spoofed IP addresses, overloading the server with Windows that will never be used, blocking the service for normal users.

## 7 Domain Name System
### 1
Packet loss is not a problem, as DNS sends small packages that have no lifetime / arent unique and can be sent multiple times. Packet loss just slows down the process at most. DNS can also use TCP and caches as a fallback.

### 2
No, the client just sets the TC-Flag, telling the server that the package is too big, causing both to swtich to TCP.

### 3
It depends. When the information needs to be updated every few seconds, a small TTL can be of good use. If the connection is stable and the information is not quick to be changed, a long TLL can be used.


