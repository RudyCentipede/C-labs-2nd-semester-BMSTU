#include "matrix.h"

int scan_matrix(matrix_t a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}

size_t del_column(matrix_t a, size_t index, size_t n)
{
    for (size_t  i = 0; i < n; i++)
    {
        size_t k = 0;
        for (size_t j = 0; j < n; j++)
        {
            if (j != index)
            {
                k++;
                a[i][k - 1] = a[i][j];
            }
        }
    }
    return n - 1;
}

size_t column_index_second_max_above_side_diag(matrix_t a, size_t n)
{
    int first_max = a[0][0];
    int second_max = a[0][0];
    size_t index;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (i + j < n + 1 && first_max < a[i][j])
                first_max = a[i][j];

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (i + j < n + 1 && second_max < a[i][j] && second_max < first_max)
            {
                first_max = a[i][j];
                index = j;
            }
    return index;
}

void print_matrix(matrix_t a, size_t n, size_t m)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
