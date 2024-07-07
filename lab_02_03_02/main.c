#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define OK 0
#define N_INPUT_ERR 1
#define EL_INPUT_ERR 2
#define EMPTY_ARRAY_ERR 3

#define NMAX 10

int input_array(int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return 1;
    return 0;
}

bool is_square(int number)
{
    return (int)sqrt(number) * (int)sqrt(number) == number;
}

size_t delete_squares(int *a, size_t n)
{
    size_t j = 0;
    for (size_t i = 0; i < n; i++)
        if (!is_square(a[i]))
        {
            j++;
            a[j - 1] = a[i];
        }
    return j;
}

void print_array(int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main(void)
{
    size_t n;
    int a[NMAX];

    printf("Please, enter number of array elements: ");

    if (scanf("%zu", &n) != 1 || n > NMAX || n == 0)
    {
        printf("Incorrect input. Number has to be positive and less than maximum.");
        return N_INPUT_ERR;
    }

    printf("Please, enter elements of array: ");

    if (input_array(a, n) != 0)
    {
        printf("Incorrect input of element.");
        return EL_INPUT_ERR;
    }

    size_t n_new = delete_squares(a, n);

    if (n_new == 0)
    {
        printf("Result array is empty.");
        return EMPTY_ARRAY_ERR;
    }

    printf("Result array: ");
    print_array(a, n_new);

    return OK;
}
