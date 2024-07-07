#!/bin/bash

clang -std=c99 -Wvla -Werror -fsanitize=undefined -fPIE -fno-omit-frame-pointer -g0 -c main.c file.c
clang -fsanitize=undefined -fno-omit-frame-pointer -pie main.o file.o -o app.exe -lm
