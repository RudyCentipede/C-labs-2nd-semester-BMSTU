#include "matrix.h"

void fill_matrix_bull_move(matrix_t a, size_t n, size_t m)
{
    int el = 1;
    for (size_t j = m; j > 0; j--)
    {
        if ((m - j) % 2 == 0)
            for (size_t i = n; i > 0; i--)
            {
                a[i - 1][j - 1] = el;
                el++;
            }
        else
            for (size_t i = 0; i < n; i++)
            {
                a[i][j - 1] = el;
                el++;
            }
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
