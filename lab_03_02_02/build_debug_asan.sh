#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g0 -c main.c matrix.c array.c digit_sum.c
clang -fsanitize=address -fno-omit-frame-pointer main.o matrix.o array.o digit_sum.o -o app.exe -lm
