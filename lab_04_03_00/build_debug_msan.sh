#!/bin/bash

clang -std=c99 -fsanitize=memory -fPIE -fno-omit-frame-pointer -g0 -c ./*.c
clang -fsanitize=memory -fno-omit-frame-pointer -pie ./*.o -o app.exe -lm
