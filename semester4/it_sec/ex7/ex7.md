# Exercise 7
## 1
### a)
#### Stateless / Packet Filter
Simple table, allows traffic or drops it based on set rules. Checks traffic every time, even for the same connection

#### Stateful
Monitors the state of network connections and filters packets based on connection state and rules. Can remember allowed connections.

#### Proxy
Understands application protocols and uses deep connection to inspect application layer level data.

#### Next Gen Firewall.
Combines Stateful and Proxy together with additional context

### b)
A stateful packet filter remembers the state of connections, so it doenst have to scan every body package from a TCP connection. TCP needs this, because the firewall would falsely reject TCP body packages, which would lead to a TCP timeout on the other end.

### c)
Default deny means to deny everything that isnt whitelisted.

Default allow means to allow everything that isnt blacklisted.

Default Deny is prefered over Default allow, because there is more traffic that you want to block then traffic you want to allow / It is easier to allow all normal traffic then to block all malware.

### d)
The PAP is a network architecture which inclues 2 firewalls and 1 Application Gateway.

The first firewall blocks of early malicous traffic and servers as a protection fro the application Gateway.

The Application gateway opens and closes connections on the Internal Networks behalve, serving as a DMZ. It communicates with external and internal networks. If the application gateway is compromised, the internal network remains protected. 

The second firewall protects the internal network from the application gateway. It restricts which systems the application gateway can access.

### e)
A DMZ (DeMilitarized Zone) is a gateway between external networks and an internal network, which needs to be protected. The internal network is not directly exposed to the external networks, and the external networks can access certain services withing the Internal network via the DMZ.

## 2
### a)

Continous monitoring is necessary, because single steps of a breach / attack may not be detectable on their own, but only when combined. IDS and IPS only scan for singular events, leading them to maybe miss an attack.

The "assume breach" mindset assumes that the attacker is already inside the system. This means to encrypt and check every traffic, even when the traffic comes from within the system itself.

### b)

| Level     | Example Tool                |
| --------- | --------------------------- |
| Packets   | Wireshark                   |
| Flows     | NetFlow                     |
| Logs      | Firewall / Server logs, ... |
| Alerts    | IDS, IPS, anti-malware      |
| Incidents | Everywhere                  |

### c)

A SIEM is an Security Information and Event Manager which collects, monitors and evaluates Security Informations from all over the system. It fills the missing gaps from IDS and IPS.

Core features:

+ Aggregation: It collects information from multiples sources within the system, such as NIDS, HIDS, firewalls and other server endpoints.
+ Normalization: It unifies all given information into a single format.
+ Correlation: It finds correlations between different information, linking different events from multiple time sources together.
+ Alerting: Fires on set rules when detecting anomalies.
+ Retention: Long term storage

### d)

- L1 Triage: Monitors SIEM and other systems, filtering out false positives. Fires if something is a "real" threat.
- L2 Investigation: Analyses the root of the breach, starts early counter measures automatically.
- L3 Threat Hunting: Searches for possible threat sources in the system, aims to find weak links.

### e)
MTTD = Mean time to detect, e.g. how long till the breach was detected.

MTTR = Mean time to recover, e.g. how long till the breach was recovered from.

Alert fatigue means that the detection system fires to often, leading to real threats getting confused with yet another false alert.

### f)

1. Prepare: Build up security system, set roles, set up tools, ...
2. Detect: Detect the breach, alert, triage
3. Contain: Isolate the host, block malicious traffic
4. Eradicate: Remove cause / malicious data
5. Recover: Restore lost data (e.g. load backup), validate still present data
6. Improve: Learn from the mistakes made -> back to prepare

Key outcome: Improve

## 3
### a)
The fundamental problem with perimeter-based security, e.g. "everything outside is unsafe, __everything inside is safe__", is that the last part does not hold true anymore (or ever). Attackers using the software of the system itself is not a new thing (Spies in War). 

New trens that make this worse:

1. Cloud computing -> In this architecture, the line between Internal and External Network blurres. The external network directly uses software from the internal network, and even computes data for it, which can be altered or faked intirely. (Cheating in Videogames is heavily affected by this)

2. Mobile Work / Home office -> Employes work with internal data and software while beeing on external networks or even external machines. 

### b)

1. Assume breach -> Permanently monitor, encrypt & segment all
2. Never trust -> Traffic location / origin is not a trust factor; just because something comes from inside the network, it doesnt mean its safe. 
3. Always verify -> every request needs to be autheticated, authoarized and validated
4. Least privilges -> Minimal acces rights, just-enough time and access

### c)
Once the Attack is trough the DMZ / PAP's second firewall, its over. Those architectures dont include any security inside the host itself on their own. Zero Trust however doesnt care where traffic comes from, so an attack may have an evenly hard time causing damage to the system independent of beeing inside of outside of it.