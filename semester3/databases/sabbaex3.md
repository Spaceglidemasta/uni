# Exercise 3

## 1
### Dataset: 
A Dataset is an array of Tupels, also known as a table

### Domain: 

A domain is the range a single attribut can have, e.g. "an integer between 0 and 255", "A string with the maximum size of 32"

### Null value:

## 2
This picture discribes the architecture of a DB.

The DBMS sends the Insertion / Query request with the data into the Dateimanager, who checks where the Data is supposed to be Inserted / Retrieved from. The Festspeichermanager then takes / inserts the data from / into the physical DB und retrieves / saves it.

Retrieved data is then parsed back trough the architecture to the DBMS.

## 3
1. Physical clustering, so that values that are often queried together are stored together.


2. In Intra-File Clustering, data is aranged in a way, so that similar data within in a given file is closer together, In Inter-File Clustering, the data of 1 File is spread over a distance in such a way, that similar data from different files in clustered together.

## 4
1. External: The interface the operators of the DB interact with

2. Conceptual: The layer where commands from the operator are interpretered and executed upon the physical database

3. Physical Database: the physical storage of the data

## 5
Altough the Datalanguage is written on the External layer, it primary lies in the __Conceputal Layer__, because there the data language is interpretered and excecuted upon the Physical layer of the DB. It cannot be in the physical layer, because that is just where the data lies, there are no operations possible, and the external layer is external to the DB, so a switch in the DBMS would change the Data language, which would / could break the DB

## 6
### __DDL: Data Definition Language__:
This part of the Data language changes , creates and deletes Structures of data, like tables, datasets, attributes and tuples.

### __DML: Data Manipulating Language__:
This part of the Data language changes , creates and deletes data iself.

## 7
### logical independence:
You can change the Structure of the Data without changing the applications interacting with the DB.

### physical independence:
You can change the Physical location of the Data without changing the locigal structure or applications interacting with the DB.

## 8
1. Backup and Recovery
2. Efficiency and Perfomance
3. Security and Access Control

## 9
- Transaction Management
    - Ensuring that Transactions like data transfare are done reliably
    
- Security
- Backup & Recovery
