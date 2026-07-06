# Exercise 8

## 1 Identity Lifecycle and Directory Services

### a)

#### Identification

To Identificate someone means to have an abstract view on who the person claims to be.

Example: Username, Email Address, ...

#### Authentification

Authentification means to authentify the idententy of someone. This can be done via something they have, know, or are

Example: Password, (physical) keys, fingerprints, ... 

#### Authorization

Authorization means to find out what the authentic identity can or cannot do.

Example: Unix groups, (team) Roles , (military) Ranks, ...

#### Accountability

Accountability is the (system-bound) result from the 3 previous steps of an Identity Lifecycle. It (hopefully) securely represents a person / user, and what this user can and cannot do.

### b)

Theoretically, both just represent a person / user. In practice however, an Identity is just an abstract information which represents the first stept to accountability. This can be a name, email adress or UID. An account however aims to securely and integrerely represent said person via a system bound collection of information and privilages (a literal account). This is needed in practice, because there anyone can just claim to be person A, without beeing Authenticated or Authorized.

### c)

This livecycle describes the action of adding, managing and removing an "account" from a system or database.

#### Joiner
At this stage a new account / user is created / registrated in the system with all minimum needed credentials / roles & permissions in order to authenticate and authorize them.

#### Mover
At this stage the credentials and roles & permissions of the user is beeing modified. This can extend to adding or removing acces / roles, changing personal information required for autherization & authorization, or other changes that impact authe. and autho.

#### Leaver
At this stage the users system intern identity abstraction is removed completely, with all traces and access right / possibilities, such as keys or other means of autho. and authe. beeing deleted and / or made invalid.

### d)

#### LDAP

LDAP is a directory protocol / service which structures a given database into multiple hirachial entries which all have a DN (distinguished name). In practice, this extends to dn (domain name, e.g. dn=google, dn=com), ou (organisatorial unit e.g. ou=groups, ou=users) and cn (concrete name e.g. cn=Luca, cn=Teacher). This makes it very effective for requesting and queuering data into the system.

#### AD (Active Directory)

AD adds makes it a full flesh-out directory system: LDAP + authN + authZ + DNS + group policy / roles / ...

### e)

| x      | centralized                             | federated                                 |
| ------ | --------------------------------------- | ----------------------------------------- |
| pro    | easy to manage, all data in 1 place     | more secure, multiple points need to fail |
| contra | less secure, only 1 point needs to fail | less easy to manage, multiple endpoints   |

## 2 Authentication Mechanisms and Access Control Model

### a)

#### "Something you know"

password, prvkey, ...

#### "Something you are"

fingerprint, eyescan, ...

#### "Something you have"

(phisical) key, authenticator app on different device

The reason why two credentials from the same category do not qualify as multi factor authN is because most of the time, a whole factor is compromised and not one single element. If they have your password from your database / phishing, they also got your username and maybe also the second password. If can fake your fingerprint, they can also fake your eyescan, but they dont know your password or / and have your keys.

If one factor can be compromised through the same attack vector as another, they are not independent factors.

### b)

The counter (y) is not a normal counter but a value $y = \frac{t_\text{now} - t_0}{x}$ where $x$ is the TTL of the key. For this to work properly, the on both systems has to be synchronized. TOTP does not solve the weakness of authorization. TOTP does not know if the HOTP was confirmed by the a corrupt system, or wether the system has been took over. Another one is real-time-phishing.

### c)

FIDO2/WebAuthn are more phishing-resistant then TOTP because they require a private key, which stays on the machine of the user and is never given away, not even on login screens. This way, phishing sites cannot utilisize human error, because there is no error to be made. The system handles the signuture itself. 

### d)

|               | DAC           | MAC          | RBAC  | ABAC       |
| ------------- | ------------- | ------------ | ----- | ---------- |
| who sets      | owner         | system/admin | admin | admin      |
| what based on | owner decides | labels       | role  | attributes |


### e)

Never trust, always verify.

1. Always authorize, even if the message / request comes from inside the system
2. least priviliges, only give out least possible permissions to do the requested task
3. assume breach: assume that the system has already been compromised