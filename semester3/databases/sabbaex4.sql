SELECT City , Count(City) as qty
FROM zip
GROUP BY City
ORDER BY DESC
LIMIT 3