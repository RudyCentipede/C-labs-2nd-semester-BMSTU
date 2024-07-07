#!/bin/bash

if [ ! -f "$1" ]; then
    if echo "$3" | grep -Eq "^-v$"; then
        echo Ошибка! Файл 1 не найден!
    fi
    exit 2
fi
if [ ! -f "$2" ]; then
    if echo "$3" | grep -Eq "^-v$"; then
        echo Ошибка! Файл 2 не найден!
    fi
    exit 3
fi


if [ ! -r "$1" ]; then
    if echo "$3" | grep -Eq "^-v$"; then
        echo Ошибка! У вас нет прав доступа к файлу 1!
    fi
    exit 4
fi
if [ ! -r "$2" ]; then
    if echo "$3" | grep -Eq "^-v$"; then
        echo Ошибка! У вас нет прав доступа к файлу 2!
    fi
    exit 5
fi

file1=$(cat "$1")
file1=${file1#*Result: }
file2=$(cat "$2")
file2=${file2#*Result: }

if [[ "$file1" != "$file2" ]]; then
    exit 1
fi

exit 0
