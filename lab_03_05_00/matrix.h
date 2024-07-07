#ifndef MATRIX_H__
#define MATRIX_H__

#include <stdio.h>
#include "array.h"

#define NMAX 10
#define MMAX 10

typedef int matrix_t [NMAX][MMAX];

int scan_matrix(matrix_t a, size_t n, size_t m);
size_t fill_array_matrix_primes(int arr[], matrix_t a, size_t n, size_t m);
void replace_matrix_primes(matrix_t a, int arr[], size_t n, size_t m);
void print_matrix(matrix_t a, size_t n, size_t m);

#endif // MATRIX_H__


