#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g0 -c main.c matrix.c
clang -fsanitize=address -fno-omit-frame-pointer main.o matrix.o -o app.exe -lm
