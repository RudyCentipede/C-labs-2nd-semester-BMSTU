#include "matrix.h"
#include "array.h"

int scan_matrix(matrix_t a, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}

void sort_lines(matrix_t a, size_t n, size_t m)
{
    int buff [MMAX];
    for (size_t i = 0; i < n; i++)
    {
        size_t jmax = i;
        for (size_t j = i + 1; j < n; j++)
            if (prod_elems(a[j], m) < prod_elems(a[jmax], m))
                jmax = j;
        copy_elems(buff, a[jmax], m);
        for (size_t k = jmax; k > i; k--)
            copy_elems(a[k], a[k - 1], m);
        copy_elems(a[i], buff, m);
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
