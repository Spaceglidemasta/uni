# Exercise 4
## 1
### a)
```SQL
SELECT COUNT(*) FROM ZIP
```

### b)
```SQL
SELECT COUNT(*) AS COLUMNS
FROM information_schema.columns
WHERE table_shema = 'db_ws_25'
AND table_name = 'zip'
```

## 2
```SQL
SELECT zip_code AS ZIP, City AS CITY FROM zip
```

## 3
### a)
```SQL
SELECT City
FROM zip
GROUP BY City
```

### b)
```SQL
SELECT City
FROM zip
GROUP BY City
ORDER BY City ASC
```

### c)
```SQL
SELECT City
FROM zip
GROUP BY City
ORDER BY City DESC
```

## 4
```SQL
SELECT Count(City)
FROM zip
GROUP BY City LIKE 'BE%'
```

## 5
### a)
```SQL
SELECT City
FROM zip
WHERE zip_code BETWEEN 60000 AND 91234
```
### b)
```SQL
SELECT City
FROM zip
WHERE zip_code > 60000 AND zip_code < 91234
```

## 6
```SQL
SELECT zip_code, city
FROM zip
WHERE City IN ('Berlin','Frankfurt', 'Aachen')
```

## 7
```SQL
SELECT City
FROM zip
WHERE City LIKE 'B__n'
```

## 8
They differ because OR has a higher priority in SQL then AND, resulting in 

    WHERE city LIKE 'B__N' AND zip_code < '30000' OR city = 'Dietzenbach';

beeing equivalent to

    WHERE (city LIKE 'B__N' AND zip_code < '30000') OR (city = 'Dietzenbach');

which is trivially different then b's:

    WHERE city LIKE 'B__N' AND (zip_code < '30000' OR city = 'Dietzenbach');

## 9
_Zip codes are always uniqe? Couldnt find one duplicate._
```SQL
SELECT zip_code, city
FROM zip
WHERE city = 'Hamburg'
```

