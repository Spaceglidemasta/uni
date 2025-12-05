# Exercise 2

## 1

### 1

|  TCP/IP Reference Model   |  Hybrid Reference Model   |  OSI Reference Model   |
| :----: | :----:     | :----: |
|   Application Layer |Application Layer |  Application-, Presentation-, Session Layer   |
|   Transport Layer |Transport Layer |  Transport Layer   |
|Internet Layer |Internet Layer | Network Layer |
| Link layer | Data Link- & Physical Layer | Data Link- & Physical Layer |

### 2

Frames, Packets, Segments and Signals

__Physical Layer__: Signals - 
as it sends physical 0's and 1's (Signals)

__Data Link Layer__: Packets, frames -
as it packs the packets from the network layer into frames and transmits them via a physical network from one device to another.

__Network Layer__: Packets, Segments, frames - 
unpacks  the packets in the frames from the data link layer and packs the segments of the transport layer into packets

__Transport Layer__: Segments, packets -
as it packs the data of the application layer into segments and unpacks the segments inside the packets from the network layer

__Application Layer__:Segments -
the segments are passed into the corresponding protocol (e.g., HTTP(s), DNS, SSH, etc.)

### 3

The presentation- and session layer are rarely used, because in modern devices, the functionality of the presentation layer is often already present in the application layer, and the session layer is rarely needed for the transport layer.

## 2

### 1
the baud rate shows how often the signal changes per sec. and the bit rate shows how many bits are beeing transfered per second, which equals if the bitrate is 1.

(bit/s) / baud = bit per message

### 2
1 bit/s = 1 baud

### 3
no, because this would mean that you need less then 1 bit per signal.

### 4
because in order to talk in symbols per second / baud, it is imperative, that the bit size of each message is fixed and equal, or else the value of 1 baud changes randomly.

## 3

### 1

CN's need Line codes in order to know the maximal number of signals that can be transmitted trough the transmission media that is used.


### 2

The NRZ works on a binary encoding where the logical 0 is assigned to a low value of the physical signal, and the 1 is assigned a high value of the physical signal (e.g. -5V & + 5V). The physical signals are then encoded into 0 and 1 respectivly.

### 3

#### Problem 1: Baseline wanderer
The Baseline is the average Signal strenght of the recieved signals, which is used to determine if the recieved signal is a 0 or 1. If the signal is under the baseline strenght / voltage, the signal is encoded to a 0, if it is above its encoded into a 1; But over a long signal this average Baseline may shift, which makes it hard to determine if the recieved signal is a 0 or a 1.

#### Problem 2: Clock Recovery
In order to decode the physical signal, the clocks of the sender and reciever need to be synchronous. This however, can lead to a problem where if one clock is slower then the other, the decoding can fail. In order to fix this, a second clock-line may be laid from the sender to the reciever, which only transmits the clock signal, synchronising the clock of the reciever with the clock of the sender. This however is old practice and not used in CN anymore, because its expensive and a lot of work to always lay out 2 cable-lines for 1 signal.

### 4

(Differential) Manchester Code (I & II) and
(Unipolar) Return to Zero


## 4

### 1
33.6kbit/s = 33600bit/s

33600 / 3429 = 9.79' 

Practically, there needs to be space for 10 bits in a single symbol.

### 2

Because modulation schemes are way more resistant to disturbances in the frequency.

Also, because different frequencies are used, multiple signals can be transmitted at the same time.

### 3

\-

### 4

\-

## 5

### 1

Twisted-pair-, fiber-optic-, and coaxial cables.

### 2
Twisted pair cables are full duplex, meaning both sides can send and recieve __simultaneously__.

Coaxial cables however are half-duplex, meaning that they can box send and recieve signals, but not __simultaneously__: Like a walk-e-talkie.

### 3

Fiber opict wires are faster and less prone to errors compared to copper wires, but can only transmit binary (modern fiber optics can).

### 4

#### The Transmission range
is the maximum range in which a signal can be transmitted without interferences.

#### The interference range
is the maximum range in which a signal can interfere with other nodes.

### 5
- Interferences
- Broadcast medium problems with 3rd parties

### 6 
Many wireless networks still work with omnidirectional transmission systems, because the recievers of the signals are often very mobile and need to be reached from many different places, which is not what directed wireless transmission is good at.

### 7

Attenuation affects unguided networks more then guided ones, because the signals of guided networks are more protected from physical interference due to guide / cable they are located in.

### 8
Ethernet & Wi-Fi

### 9
TCP / IP

### 10

2.4GHz - 5GHz

### 11

WLAN achieves a higher power output, due to it beeing designed to operate over longer ranges then bluetooth, which is for short range user-to-device communication.

## 6

### 1

I would chose Network 4, as it doesnt interfere with any other network and it having a decent signal strentgh

### 2

- Interference with other networks: Every network but network 4
- Low signal strentgh: Network 1 and 3

### 3

11 Mbps

### 4

- Network 1 and 3 heavily interfere with each other and network 2, which can cause packet loss.
- Network 5 and 6 are exactly on the same channel, also leading to strong interferences -> packet loss.
- Network 1 is weak af.

## 7


### 1

#### 16-QAM (16-state Quadrature Amplitude Modulation):
9600 / 2400 = __4 bits per signal__

2 ^ 4 = 16 -> "16-QAM"

### 2

floppy disks.

### 3

The acces over ISDN was more reliable and stable

### 4

Cap´n Crunches cereal boxes used to have a whistle-toy inside, that could produce sounds at 2.6KHz, which was the same frueqency telephone lines used to start / end calls. This allowed him to trick the line into thinking the call was over, giving him free & unlimited long distance calls.