# Exercise 6 
## 1
### a)
#### IDS (Intrusion Detection System)
Can detect malicious traffic and alarm authorities, but has no impcat on the actual traffic itself.

#### IPS (Intrusion Protection System)
An IPS can also detect malicious traffic, with the added benefit / downside that takes action on its own. This can increase downtime between detection and action, but also imposes a risk of false positives.

### b)
A NIDS (Network IDS) runs on the interface of the Host, working with the traffic before it reaches the host. On the other hand, an HIDS (Host IDS) works on the Host machine itself.

### c)
Suspicious event order
Changes to important data
Usage of high privilage abilities

### d)
Number of false positives and false negatives

### e)
A Signature IDS compares incoming traffic / Signals with known patterns from a DB.

Because of this, the IDS is more precise and the false negative rate is lower.

### f)
Anomaly detection works by telling the System what "normal" behavior should look like. If traffic derives from this "normal" behavior by a certain degree, the IDS shoots alarm.

## 2
| Direction | Source Ip     | Destination Ip | Transport Protocol | Source Port | Dest. Port | Flags | Action |
| --------- | ------------- | -------------- | ------------------ | ----------- | ---------- | ----- | ------ |
| OUT       | 172.16.0.11   | ANY            | TCP                | ANY         | 25         | SYN   | ALLOW  |
| IN        | ANY           | 172.16.0.11    | TCP                | 25          | ANY        | ACK   | ALLOW  |
| OUT       | 172.16.0.0/12 | ANY            | TCP                | ANY         | 80         | SYN   | ALLOW  |
| IN        | ANY           | 172.16.0.0/12  | TCP                | 80          | ANY        | ACK   | ALLOW  |
| DEFAULT   | ANY           | ANY            | ANY                | ANY         | ANY        | ANY   | DENY   |