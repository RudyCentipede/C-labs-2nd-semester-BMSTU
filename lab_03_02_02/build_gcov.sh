#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -c -O0 -g3 -coverage main.c matrix.c array.c digit_sum.c
gcc main.o matrix.o array.o digit_sum.o -o app.exe -coverage -lm