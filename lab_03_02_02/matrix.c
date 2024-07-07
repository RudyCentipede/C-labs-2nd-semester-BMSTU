#include "matrix.h"

int scan_matrix(matrix_t a, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}

size_t insert_line(matrix_t a, int ins_line[], size_t n, size_t m)
{
    size_t i = 0;
    size_t end = n;
    while (i < end)
        if (count_odd_digits_sum_elems(a[i], m) >= 2)
        {
            for (size_t j = end; j > i; j--)
                copy_elems(a[j], a[j - 1], m);
            copy_elems(a[i], ins_line, m);
            i += 2;
            end++;
        }
        else
            i++;

    return end;
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
