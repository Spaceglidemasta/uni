# Exercise 7

## 1

### a)
The deletion gets gestricted: 
```SQL
delete from zip where id = 10084
```

    Error Code: 1451. Cannot delete or update a parent row: a foreign key constraint fails (`db_ws_25`.`person`, CONSTRAINT `fk_person2zip` FOREIGN KEY (`zip_id`) REFERENCES `zip` (`ID`) ON DELETE RESTRICT ON UPDATE RESTRICT)

This happens because deletion of foreign keys got restricted
when creating the table:
```SQL
CONSTRAINT fk_person2zip
    FOREIGN KEY (`zip_id`)
    REFERENCES zip(`ID`)
    ON UPDATE RESTRICT
    ON DELETE RESTRICT
```




### b)
The deletion is successfully executed:
```SQL
delete from zip where id = 10085
```
    1 row(s) affected


## 2
### a)
```SQL
drop table if exists gender;

create table gender (
	id int not null primary key auto_increment,
    gender varchar(20)
)
```

### b)
```SQL
lock table gender write;

insert into gender (`gender`) values
	('Mr.'), ('Mrs.');
    
unlock table;
```

### c)
https://stackoverflow.com/questions/861146/can-you-replace-or-update-a-sql-constraint

https://stackoverflow.com/questions/21659691/error-1452-cannot-add-or-update-a-child-row-a-foreign-key-constraint-fails
```SQL
SET FOREIGN_KEY_CHECKS=0;
alter table person

add constraint fk_person2gender
	foreign key (gender)
    references gender(id)
    on update restrict
    on delete restrict
```

Also correcting the mistake with gender beeing 0 and 1, despite PKs
always starting with 1 and therefore beeing 1 and 2

## 3
### a)

    R: M1 x M2 = {
                {3,drei}, {3,neun},
                {9,drei}, {9,neun},
                {12,drei}, {12,neun}
                }

### b)
no, because this is not true for 4 of the 6 subsets.

### c)

| R         |     3     |     9      |     12    | 
|-----------|-----------|------------|-----------|
| drei      | {3,drei}  | {9,drei}   | {12,drei} |
| neun      | {3,neun}  | {9,neun}   | {12,neun} |

### d)
tuples

### e)

    [R]: M2 x M1 = {
        {drei, 3}, ...
    }

## 4

1. Relation are not allowed to have duplicates, tables are.
2. Relations dont have a order of Columns and Rows, tables do.
3. Relations can have 0 columns, tables apperently need to have atleast  1

## 5
### a)
5 and 2

### b)
6 and 2