# Exercise 5
## 1
### a)
```SQL
SELECT left(zip_code, 2) as ZIP_short
FROM zip
```
### b)
```SQL
SELECT City , Count(City) as qty
FROM zip
GROUP BY City
```
### c)
```SQL
SELECT City
FROM zip
GROUP BY City HAVING Count(City) = 1
```
### d)
Because there is no City specifically named "Frankfurt", there is only "Frankfurt am Main" and "Frankfurt and der Oder"
### e)
```SQL
SELECT City , Count(City) as qty
FROM zip
GROUP BY City
ORDER BY qty DESC
LIMIT 3
```

## 2
A Relational DB Model is a List of Tables, which are a list of Tuples, which are an array of Attributes.

Each table has a Primary key, which represents an unique identifier for each tuple.

There can be Relationships between Tables via foreign keys.

Data Independence: They way the Data is structured logically is independent from the way its stored physically, which allows the DB to optimize its Memory.

## 3
- The PK is the INDEX of a Table. It has to be unique for every Tuple. Sometimes it follows AUTO_INCREMENT.

## 4
"Irreducibility or minimalism in uniqueness" = a key has just enough attributes to be unique, nothing more.

## 5
Candidate Keys = {ID, {Nachname, Vorname}, Emailadresse}

### a)
__ID__ is minimalistic and enough to uniquelly identify each person.

__Nachname, Vorname__ is more direct and readable, but can fail because some persons have the exact same Name and Surname. This is a terrible idea.

__Emailadresse__ is better then using names, because most people have unique email adresses, but some may share one, altough this can be forbiddened by the System.

### b)
__ID__ is by far the best choice here. Altough Emailadresse is probably still posible, a unique UID is always the best PK.

## 6)
In order to have a clear and defined way to differentiate between data inside of the System. If every key can be not unique, one could not tell the difference between some objects, and therefore they become the same / one is lost.

## 7)
- __Pro:__ Some attributes dont need a value, and there needs to be a concise way to give them no value. Especially when using Strings as attributes, an empty space is often times not enough.
- __Contra:__ Using nullable attributes can lead to bugs where queried data cannot be extracted because its Null. This either leads to false information, or it can cause crashes.

## 8)
This Table is terrible. There should be 3 Tables: 

one Table for the Students

    | PK:Student_id | first_name | last_name | ...

one for the courses

    | PK:course_id | course_name | Professor | ...

and one for the Participation of these courses

    | foreignkey:Student_id | foreignkey:course_id |

This way, the existance of every student ist concise, and it is still possible to querery which student attends which course.