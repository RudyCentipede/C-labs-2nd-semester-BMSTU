#include "matrix.h"
#include "array.h"

#define OK 0
#define N_INPUT_ERR 1
#define M_INPUT_ERR 2
#define EL_INPUT_ERR 3

#define NMAX 10
#define MMAX 10


int main(void)
{
    matrix_t a;
    size_t n;
    size_t m;
    int ins_line [MMAX];
    size_t new_n;

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

    printf("Please, enter elements of matrix: ");

    if (scan_matrix(a, n, m) != 0)
    {
        printf("Incorrect input of element.");
        return EL_INPUT_ERR;
    }

    for (size_t i = 0; i < m; i++)
    {
        ins_line[i] = -1;
    }

    new_n = insert_line(a, ins_line, n, m);
    print_matrix(a, new_n, m);

    return OK;
}
