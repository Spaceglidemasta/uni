# Exercise 6

## 1 & 2
```SQL

DROP TABLE IF EXISTS `person`;
CREATE TABLE `person` (
	`id` INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `gender` INT NOT NULL,
    `nnam` varchar(60) NOT NULL,
    `fnam` varchar(60) NOT NULL,
    `bdate` timestamp NOT NULL DEFAULT '2014-01-01 06:30:00',
    `zip_id` int,
    `str` varchar(60) NOT NULL,
    `tel` varchar(40) NOT NULL,
    `mobil` varchar(40) NOT NULL,
    
    CONSTRAINT fk_person2zip
		FOREIGN KEY (`zip_id`)
		REFERENCES zip(`ID`)
        ON UPDATE RESTRICT
        ON DELETE RESTRICT
)
```

## 3

```SQL
LOCK TABLE `person` WRITE;
INSERT INTO `person` (`gender`, `nnam`, `fnam`, `bdate`, `zip_id`, `str`, `tel`, `mobil`) VALUES
	(1, 'De Simone', 'Luca', '2005-06-09 02:00:00', 10084, 'Gingstraße', '63', '165'),
    (1, 'Le Mimone', 'Tuca', '2006-01-01 03:33:33', 10084, 'Blingstraße', '69', '187'),
    (0, 'Cheeks', 'Sandy', '2005-01-01 02:00:00', 10084, 'Zingstraße', '63', '165'),
    (0, 'Mertens', 'Angela', '2000-01-01 02:00:00', 1868, 'Berlinstraße', '110', '112');
UNLOCK TABLE;
```
Testing:
```SQL
SELECT 
    person.fnam,
    person.nnam,
    zip.city
FROM person
JOIN zip ON person.zip_id = zip.id;
```
Output:
```
fnam   |  nnam         |  city
-------+---------------+-----------
Luca   |  "De Simone"  |  Mühlheim
Tuca   |  "Le Mimone"  |  Mühlheim
Sandy  |  "De Simone"  |  Mühlheim
Angela |  Mertens      |  Berlin
```