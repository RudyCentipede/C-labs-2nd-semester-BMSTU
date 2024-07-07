#ifndef MATRIX_H__
#define MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define NMAX 10
#define MMAX 10

typedef int matrix_t [2 * NMAX][MMAX];

int scan_matrix(matrix_t a, size_t n, size_t m);
size_t insert_line(matrix_t a, int ins_line[], size_t n, size_t m);
void print_matrix(matrix_t a, size_t n, size_t m);

#endif // MATRIX_H__
