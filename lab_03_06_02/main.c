#include "matrix.h"

#define OK 0
#define N_INPUT_ERR 1
#define M_INPUT_ERR 2

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

    if (scanf("%zu", &m) != 1 || m > MMAX || m == 0)
    {
        printf("Input error. Number of columns in matrix has to be positive and less than maximum.");
        return M_INPUT_ERR;
    }

    fill_matrix_bull_move(a, n, m);
    print_matrix(a, n, m);
    return OK;
}
