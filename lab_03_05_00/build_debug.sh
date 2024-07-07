#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -c -O0 -g3 main.c matrix.c array.c primes.c
gcc main.o matrix.o array.o primes.o -o app.exe -lm