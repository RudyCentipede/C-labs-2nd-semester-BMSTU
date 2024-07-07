#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

typedef int matrix_t [NMAX][NMAX];

int scan_matrix(matrix_t a, size_t n);
size_t column_index_second_max_above_side_diag(matrix_t a, size_t n);
size_t del_column(matrix_t a, size_t index, size_t n);
void print_matrix(matrix_t a, size_t n, size_t m);

#endif //MATRIX_H
