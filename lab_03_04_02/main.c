#include "matrix.h"

#define OK 0
#define N_INPUT_ERR 1
#define M_INPUT_ERR 2
#define NOT_SQUARE_MATRIX 3
#define EL_INPUT_ERR 4
#define NO_MAX_EL_ERR 5

int main(void)
{
    matrix_t a;
    size_t n;
    size_t m;
    int max;

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
        printf("Error. Numbers of lines and columns in square matrix must be equal.");
        return NOT_SQUARE_MATRIX;
    }

    printf("Please, enter elements of matrix: ");

    if (scan_matrix(a, n) != 0)
    {
        printf("Incorrect input of element.");
        return EL_INPUT_ERR;
    }

    if (n == 1)
    {
        printf("Error. There is no suitable element.");
        return NO_MAX_EL_ERR;
    }

    max = max_ends_five_under_side_diag(a, n);

    if (abs(max) % 10 != 5)
    {
        printf("Error. There is no suitable element.");
        return NO_MAX_EL_ERR;
    }
    printf("The maximum element which ends with the digit five and is located under the side diagonal: %d", max);
    return OK;
}

