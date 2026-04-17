# Exam

## 1
Redundancies are data that is stored twice or more, leading to more memory usage and inconsitencies with foreign keys.

An example for this would be storing 2 tables that store the identical data.

## 2
A PK (Primary Key) is used to uniquely identify each tupel of a table.

To fullfill this job, it has 3 important attributes:
- it cannot be NULL
- it is unique for every Tupel of the Table
- it is immutable
- (its implementation is minimal, extending to an integer most of the time.)
- (it should be free of user information)

## Candidate keys
ID, Email, Name + Vorname

Advantages:
- ID:
    - minimal
    - unique
- Email:
    - restricts the system to 1 user per Email
- Name + Vorname:
    - /

Disadvantages:
- ID:
    - /
- Email:
    - restricts the system to 1 user per Email
    - contains personal information about the entry
- Name + Vorname
    - contains personal information about the entry
    - restricts the system to 1 user per Surname + Name usage
    - not unique


correct, correct, false

3rd PK -> Name + Vorname + Gb. + Gb-Ort
-> bauchgefühl war richtig

## 3

Null values are values that are empty / represent the absence of a value.
The advantage is that this can make a value optional. The disadvantage is that this can cause problems when a value is expected, which is why a PK can never be NULLABLE. They also complicate boolean operations by extending the results to TRUE / FALSE / UNKNOWN.

## 5
Result:
1,...,6,8,...,12
Result:
2,...,10
Result:
1,...,6,9,...,12

## 6

{
    (1,one), {1,four}, {1,ten}
    {4,one}, {4,four}, {4,ten}
    {10,one}, {10,four}, {10,ten}  
}

{} -> ()

R = M1xM2

| R    | 1      | 4      | 10      |
| ---- | ------ | ------ | ------- |
| one  | 1,one  | 4,one  | 10,one  |
| four | 1,four | 4,four | 10,four |
| ten  | 1,ten  | 4,ten  | 10,ten  |

-> falsch, mit suitable Relation meint er eine die sinn macht. Korrektur:


R ⊆ M1xM2

R = {(1,one),(4,four),(10,ten)}

Table:
| R   | one | four | ten |
| --- | --- | ---- | --- |
| 1   | 1   | 0    | 0   |
| 4   | 0   | 1    | 0   |
| 10  | 0   | 0    | 1   |

## 13

```SQL
CREATE TABLE `gruppen` (
    id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    `name` varchar(50)
);

CREATE TABLE `lieferanten` (
    id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    `name` varchar(50)
);

CREATE TABLE `artikel` (
    id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    `name` varchar(50) NOT NULL,
    gruppen_id int NOT NULL,
    lieferant_id INT NOT NULL,
    preis FLOAT,

    FOREIGN KEY (gruppen_id) REFERENCES gruppen(id),
    FOREIGN KEY (lieferant_id) REFERENCES lieferanten(id)
);


LOCK TABLE `gruppen` WRITE;
LOCK TABLE `lieferanten` WRITE;
LOCK TABLE `artikel` WRITE;

INSERT INTO `gruppen` (`name`) VALUES ('Fruehstueck')
INSERT INTO `lieferanten` (`name`) VALUES ('UPS')
INSERT INTO `artikel` (`name`, gruppen_id, lieferant_id, preis) VALUES
    ('Muesli', 1, 1, 3.78)

UNLOCK TABLES;

UPDATE lieferanten WHERE `name` = 'UPS' SET `name` = 'DHL'

DELETE FROM lieferanten WHERE `name` = 'UPS'

```