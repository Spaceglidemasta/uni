# Exercise 9
##### Theorie Part

### All Operators:

- SELECT

    ```SQL
    SELECT * from company where gehalt > 4000;
    ```
- PROJECT

    ```SQL
    SELECT Mitarbeiter from company;
    ```
- UNION

    ```SQL
    SELECT Mitarbeiter from company where gehalt > 1000
    UNION
    SELECT Mitarbeiter from company where age < 30;
    ```
- DIFFERENCE

    ```SQL
    SELECT name FROM employees
    WHERE name NOT IN (
        SELECT name FROM employees WHERE age < 30
    );
    ```
- CROSS (JOIN / PRODUCT) / (CARTESIAN) PRODUCT 

    All partner combinations from 2 groups:
    ```SQL
    SELECT a.name, b.name
    FROM groupA a
    CROSS JOIN groupB b;
    ```
- JOIN 
    ```SQL
    SELECT e.name, d.department_name
    FROM employees e
    JOIN departments d
    ON e.department_id = d.id;
    ```
- DIVISION

    ```SQL
    SELECT s.student_id
    FROM student_courses s
    GROUP BY s.student_id
    HAVING COUNT(DISTINCT s.course_id) = (SELECT COUNT(*) FROM mandatory_courses);
    ```
- INTERSECTION

    ```SQL
    SELECT name, age FROM A
    INTERSECT
    SELECT name, age FROM B;
    ```

## 1
### union-compatible
Means that both relations can be united via the union operator, indirectly implying that both have the same attributes
### type-compatible
Means that both attributes have the same type

## 2
1. INTERSECT
2. DIVISION
3. UNION

## 3
1. Selection
2. Projection
3. Cartesian Product / Cross join
4. Difference

## 4
Where

## 5
Grad = 5 + 2 = 7
Card = 112 * 5 = 560

## 6

A JOIN joins 2 Relations over 1 attribute both share / have the same datatype of.

A THETA JOIN ensures that this attribute not only has the same datatype, but also that it fullfills a given condition, like

    p.age > e.age

A EQUIJOIN is a THETAJOIN that automatically applies the equal <code>==</code> operator on both attributes.

A NATURAL JOIN automatically joins all columns that have the same name in both tables.

```SQL
SELECT *
FROM Film
NATURAL JOIN Genre_Film;
```

##### Programming Part
## 1
```SQL
SELECT *
FROM person p
JOIN zip z
WHERE z.id = p.zip_id
```
## 2
```SQL
SELECT *
FROM person p
JOIN zip z
WHERE z.id <> p.zip_id
```
## 3
Weiss net ganz wasser da will
```SQL
SELECT p.*, zip_code, city
FROM person p
JOIN zip z
WHERE z.id = p.zip_id
```