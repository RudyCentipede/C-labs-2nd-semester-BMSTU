#!/bin/bash

clang -std=c99 -fsanitize=undefined -fPIE -fno-omit-frame-pointer -g0 -c main.c matrix.c array.c primes.c
clang -fsanitize=undefined -fno-omit-frame-pointer -pie main.o matrix.o array.o primes.o -o app.exe -lm
