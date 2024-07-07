#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g0 -c main.c matrix.c array.c primes.c
clang -fsanitize=address -fno-omit-frame-pointer main.o matrix.o array.o primes.o -o app.exe -lm
