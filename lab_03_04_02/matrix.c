#include "matrix.h"

int scan_matrix(matrix_t a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}

int max_ends_five_under_side_diag(matrix_t a, size_t n)
{
    int max = a[0][0];
    int cur;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (i + j >= n && abs(a[i][j]) % 10 == 5)
            {
                cur = a[i][j];
                if (max < cur || abs(max) % 10 != 5)
                    max = cur;
            }

    return max;
}
