#!/bin/bash

clang -std=c99 -Weverything -Wvla -Werror -fsanitize=address -fno-omit-frame-pointer -g0 -c main.c
clang -fsanitize=address -fno-omit-frame-pointer main.o -o app.exe -lm
