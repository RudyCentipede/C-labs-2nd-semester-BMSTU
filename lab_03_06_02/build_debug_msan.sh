#!/bin/bash

clang -std=c99 -fsanitize=memory -fPIE -fno-omit-frame-pointer -g0 -c main.c matrix.c
clang -fsanitize=memory -fno-omit-frame-pointer -pie main.o matrix.o -o app.exe -lm
