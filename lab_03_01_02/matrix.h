#ifndef MATRIX_H__
#define MATRIX_H__

#include <stdio.h>
#include <stdbool.h>

#define NMAX 10
#define MMAX 10

typedef int matrix_t [NMAX][MMAX];

int scan_matrix(matrix_t a, size_t n, size_t m);
size_t fill_array_from_matrix(int *arr, matrix_t matrix, size_t n, size_t m);
bool is_k_column_elems_alternate(matrix_t matrix, size_t n, size_t k);

#endif // MATRIX_H__
