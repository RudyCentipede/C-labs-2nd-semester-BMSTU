#!/bin/bash

clang -std=c99 -Weverything -Wvla -Werror -fsanitize=memory -fPIE -fno-omit-frame-pointer -g0 -c main.c file.c
clang -fsanitize=memory -fno-omit-frame-pointer -pie main.o file.o -o app.exe -lm
