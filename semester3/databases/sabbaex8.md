# Exercise 8
## 1
```SQL
LOCK TABLE person WRITE;
ALTER TABLE person
    add column company_name varchar(30),
    add column str_company varchar(60),
    add column zip_company_id int,
    add column tel_company varchar(40),
    add column url varchar(45),

    add CONSTRAINT fk_person2zip_company
        FOREIGN KEY (zip_company_id)
        REFERENCES zip(id)
;
UNLOCK TABLES;
```
## 2
### a)
```SQL
LOCK TABLE person WRITE;
UPDATE person
    set str_company=str where str_company is NULL;
UNLOCK TABLES;
```
### b)
```SQL
LOCK TABLE person WRITE;
ALTER TABLE person
    drop url
UNLOCK TABLES;
```
### c)
```SQL
LOCK TABLE person WRITE;
update person
    set company_name='Black Inc.';
UNLOCK TABLES;
```
## 3
```SQL
LOCK TABLE person WRITE;
ALTER TABLE person
    modify company_name varchar(60);
UNLOCK TABLES; 
```