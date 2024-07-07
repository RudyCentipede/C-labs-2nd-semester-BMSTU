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

file1=$1
file2=$2

mask="[+-]?[0-9]+(\.[0-9]+)?"

file1_numbers=$(grep -Eo "$mask" "$file1")
file2_numbers=$(grep -Eo "$mask" "$file2")


if [ "$file1_numbers" != "$file2_numbers" ]; then
    exit 1
fi

exit 0