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

file1_numbers=$(cat "$file1")
file1_numbers=${file1_numbers#*Result:}
file2_numbers=$(cat "$file2")

file1_numbers=$(echo "$file1_numbers" | tr -d ' ')
file2_numbers=$(echo "$file2_numbers" | tr -d ' ')
file1_numbers=$(echo "$file1_numbers" | sed ':a;N;$!ba;s/\n//g')
file2_numbers=$(echo "$file2_numbers" | sed ':a;N;$!ba;s/\n//g')

if [ "$file1_numbers" != "$file2_numbers" ]; then
    exit 1
fi

exit 0