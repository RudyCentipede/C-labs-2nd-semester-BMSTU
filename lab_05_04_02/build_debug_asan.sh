#!/bin/bash

clang -std=c99 -Wvla -Werror -fsanitize=address -fno-omit-frame-pointer -g0 -c main.c product.c
clang -fsanitize=address -fno-omit-frame-pointer main.o product.o -o app.exe -lm
