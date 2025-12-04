# Exercise Sheet 1 

### 1
Data Independence:
Changing the Logical Shema should not effect the External Shema or vice versa.

### 2
I think python is a bit clearer then natural language, especially because the given task already discribes the whole proccess in _natural language_.

```python
addresses = []

with open("ADDRESS") as file:
    for line in file:
        #if we can treat line as a json object
        if line["ADDRESS"] == Bonn:
            addresses.append(line)

with open("RESULT") as results:
    for line in addresses:
        results.write(line)
        print(line)
```

### 3
- Development of a reporting tool that is calculating each day the value of all items on stock: __Application Programmer__
- Updating the number of available items for a certain product: __End User__
- Deleting the account of a user who has left the company: __DB Administrator__
- Modify the storage structure of the data: __DB Administrator__
- Answer to requests by telephone about the current number of available items for a certain
product: __End User__

### 4

<table>
<tr><th>πA(R) </th><th>πB(R)</th> <th>πA,B(R)</th></tr>
<tr><td>

|__A__  
|---    
a       
c       
d  

</td><td>

|__B__
|---
b
b
e

</td><td>

|__A__  | __B__ |
|---    |---    |
a       | b
c       | b
d       | e

</td></tr> </table>