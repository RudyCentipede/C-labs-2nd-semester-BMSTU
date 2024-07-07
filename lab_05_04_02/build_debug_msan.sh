#!/bin/bash

clang -std=c99 -Wvla -Werror -fsanitize=memory -fPIE -fno-omit-frame-pointer -g0 -c main.c product.c
clang -fsanitize=memory -fno-omit-frame-pointer -pie main.o product.o -o app.exe -lm
