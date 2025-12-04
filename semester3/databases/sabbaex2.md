# Exercise 2

## 1

A Database is an array of tables, which are arrays of touples, which are arrays of attributes, which are data with datatypes.

## 2

1. The ability to store data
2. The ability to query / change & delete data
3. Consistency that the data is not changing

## 3

Redundencies is data which is no longer needed, but still left behind in the DB, which can cause unauthorized acces to this data.

## 4

1. Relational DB's
+ __Pro:__ Strong data protection, joined data always updates every related table, uses SQL
+ __Contra:__ Is slow to operate on a big scale, not very scalable.

2. NoSQL DB's
+ __Pro:__ Very fast, good scalability for big data sizes
+ __Contra:__ Harder to operate then SQL based DB's, joints between tables arent as safe and sometimes need to be copied or embedded. Data safety is not as good as in Relational DB's.

## 5

A table is the practical implementation of a Relation. Theoretically, there is no difference.

## 6

### Problems:
- Typo in Addison-Wesseley
- Vieweg and Beutelspacher were shortened to View. and Beutels., which can cause problems when searching for their respective attributes attributes.
- The book "Java als [...]" and "Entwurfsmuster" exists 2 times in the DB. This was caused by a problem where 2 Autors took part in the same book.

### Correction:

New DB:

```SQL
CREATE TABLE books (
    bookID INT AUTO_INCREMENT PRIMARY KEY,
    titel varchar(200) NOT NULL,
    verlag varchar(50) NOT NULL,
)

CREATE TABLE authors (
    authorID INT AUTO_INCREMENT PRIMARY KEY,
    `name` varchar(50) NOT NULL
)

CREATE TABLE library (
    bookID INT NOT NULL,
    authorID INT NOT NULL,
    PRIMARY KEY (bookID, autorID),
    FOREIGN KEY (book_id) REFERENCES books(book_id),
    FOREIGN KEY (author_id) REFERENCES authors(author_id)
);


LOCK TABLES books WRITE, authors WRITE, library WRITE;

INSERT INTO `books`
VALUES
    (1, `Datenbanken`, `Teubner`),
    (2, `Entwurfsmuster`, `Addison-Wesely`),
    (3, `Java als erste Programmiersprache`, `Teubner`),
    (4, `Kryptologie`, `Vieweg`),
    (5, `Diskrete Mathematik`, `Vieweg`);

INSERT INTO `authors`
VALUES
    (1, `Matthias Schubert`),
    (2, `Johnson`),
    (3, `Goll`),
    (4, `Beutelspacher`),
    (5, `Helms`);

INSERT INTO `library`
VALUES
    (1, 1),
    (2, 2),
    (2, 5),
    (3, 3),
    (3, 5),
    (4, 4),
    (5, 4);
UNLOCK TABLES;
```

## 7

### Attributes:
1. name
2. verlag

### Attribute values:
1. `Helms`
2. `Teubner`