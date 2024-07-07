#!/bin/bash

clang -std=c99 -Weverything -Wvla -Werror -fsanitize=undefined -fPIE -fno-omit-frame-pointer -g0 -c main.c
clang -fsanitize=undefined -fno-omit-frame-pointer -pie main.o -o app.exe -lm
