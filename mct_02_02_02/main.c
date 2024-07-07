#include "matrix.h"

#define OK 0
#define N_INPUT_ERR 1
#define M_INPUT_ERR 2
#define EL_INPUT_ERR 3
#define NO_SIDE_DIAG_ERR 4

int main(void)
{
    matrix_t a;
    size_t n;
    size_t m;

    printf("Please, enter number of lines in matrix: ");

    if (scanf("%zu", &n) != 1 || n > NMAX || n == 0)
    {
        printf("Input error. Number of lines in matrix has to be positive and less than maximum.");
        return N_INPUT_ERR;
    }

    printf("Please, enter number of columns in matrix: ");

    if (scanf("%zu", &m) != 1 || m > NMAX || m == 0)
    {
        printf("Input error. Number of columns in matrix has to be positive and less than maximum.");
        return M_INPUT_ERR;
    }

    if (n != m)
    {
        printf("Error. Matrix must be square.");
        return M_INPUT_ERR;
    }

    if (n <= 2)
    {
        printf("Error. There is no side diagonal in the matrix.");
        return NO_SIDE_DIAG_ERR;
    }

    printf("Please, enter elements of matrix: ");

    if (scan_matrix(a, n) != 0)
    {
        printf("Incorrect input of element.");
        return EL_INPUT_ERR;
    }

    size_t index = column_index_second_max_above_side_diag(a, n);
    n = del_column(a, index, n);
    print_matrix(a, n, m);

    return OK;
}
