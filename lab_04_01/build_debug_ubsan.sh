#!/bin/bash

clang -std=c99 -fsanitize=undefined -fPIE -fno-omit-frame-pointer -g0 -c ./*.c
clang -fsanitize=undefined -fno-omit-frame-pointer -pie ./*.o -o app.exe -lm
