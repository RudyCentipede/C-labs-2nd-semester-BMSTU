#include "matrix.h"
#include "primes.h"

int scan_matrix(matrix_t a, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}

size_t fill_array_matrix_primes(int arr[], matrix_t a, size_t n, size_t m)
{
    size_t len = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_prime(a[i][j]))
            {
                len++;
                arr[len - 1] = a[i][j];
            }
    return len;
}

void replace_matrix_primes(matrix_t a, int arr[], size_t n, size_t m)
{
    int k = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_prime(a[i][j]))
            {
                k++;
                a[i][j] = arr[k - 1];
            }
}

void print_matrix(matrix_t a, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
