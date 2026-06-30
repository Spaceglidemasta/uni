#!/bin/bash

if [ "$1" == "" ]; then
    echo "Please run like ./run.sh 5000000"
    exit 1
fi

gcc load.c -o load_1

#copy program 5 times
for i in {2..5}
do
    cp load_1 load_$i
done

for i in {1..5}
do 
    ./load_$i $i 10 15 $1 &
done