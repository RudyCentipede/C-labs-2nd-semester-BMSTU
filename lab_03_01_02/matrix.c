#include "matrix.h"

int scan_matrix(matrix_t a, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}

bool is_k_column_elems_alternate(matrix_t matrix, size_t n, size_t k)
{
    int prev = matrix[0][k];
    size_t streak = 1;
    for (size_t i = 1; i < n; i++)
    {
        if ((matrix[i][k] > 0 && prev < 0) || (matrix[i][k] < 0 && prev > 0))
            streak++;
        prev = matrix[i][k];
    }

    return streak == n && n != 1;
}

size_t fill_array_from_matrix(int *arr, matrix_t matrix, size_t n, size_t m)
{
    size_t j = 0;
    for (size_t i = 0; i < m; i++)
    {
        j++;
        if (is_k_column_elems_alternate(matrix, n, i))
            arr[j - 1] = 1;
        else
            arr[j - 1] = 0;
    }
    return j;
}
