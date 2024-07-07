#!/bin/bash

if [ ! -f "$1" ]; then
    if echo "$3" | grep -Eq "^-v$"; then
        echo "Error! File 1 not found!"
    fi
    exit 1
fi
if [ ! -f "$2" ]; then
    if echo "$3" | grep -Eq "^-v$"; then
        echo "Error! File 2 not found!"
    fi
    exit 1
fi

if [ ! -r "$1" ]; then
    if echo "$3" | grep -Eq "^-v$"; then
        echo "Error! You do not have access to file 1!"
    fi
    exit 1
fi
if [ ! -r "$2" ]; then
    if echo "$3" | grep -Eq "^-v$"; then
        echo "Error! You do not have access to file 2!"
    fi
    exit 1
fi

if [[ ! -f "$1" ||! -f "$2" ]]; then
    exit 1
fi

content1=$(tr -s '[:blank:]' '\n' < "$1")
content2=$(tr -s '[:blank:]' '\n' < "$2")

if [[ "$content1" != "$content2" ]]; then
    exit 1
fi

exit 0
