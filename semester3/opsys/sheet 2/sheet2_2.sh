#!/bin/sh

if [ $# -eq 2 ]; then
    if [ $1 -eq $2 ]; then
        echo "EQUAL"
    else
        if [ $1 -gt $2 ]; then
            echo "arg1 ($1) is bigger"
        else
            echo "arg2 ($2) is bigger"
        fi
    fi
else
    echo "invalid args"
fi