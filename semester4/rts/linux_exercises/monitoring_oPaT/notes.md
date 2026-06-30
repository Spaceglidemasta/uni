# Monitoring of Processes and Threads
## Exercises 1
### a)

    ps -u sgmasta

    <a ton of processes...>

### b)

    pstree -u sgamasta | grep -i load

    |        |--code-+-bash---load_1


###### I dont like this command
### c)

    ps -u sgamasta | grep -i load

    18667 pts/2 00:00:02 load_1