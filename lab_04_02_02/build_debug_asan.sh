#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g0 -c ./*.c
clang -fsanitize=address -fno-omit-frame-pointer ./*.o -o app.exe -lm
