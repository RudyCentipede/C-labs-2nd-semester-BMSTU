#ifndef MATRIX_H__
#define MATRIX_H__

#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

typedef int matrix_t [NMAX][NMAX];

int scan_matrix(matrix_t a, size_t n);
int max_ends_five_under_side_diag(matrix_t a, size_t n);

#endif // MATRIX_H__

