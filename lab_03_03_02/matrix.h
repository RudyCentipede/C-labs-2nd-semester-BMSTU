#ifndef MATRIX_H__
#define MATRIX_H__

#include <stdio.h>
#include <stdlib.h>

#define NMAX 10
#define MMAX 10

typedef int matrix_t [NMAX][MMAX];

int scan_matrix(matrix_t a, size_t n, size_t m);
void sort_lines(matrix_t a, size_t n, size_t m);
void print_matrix(matrix_t a, size_t n, size_t m);

#endif // MATRIX_H__
