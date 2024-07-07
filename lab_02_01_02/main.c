#include <stdio.h>

#define OK 0
#define N_INPUT_ERR 1
#define EL_INPUT_ERR 2
#define NO_NEG_VALUES 3

#define NMAX 10

int input_array(int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return 1;
    return 0;
}

double average_of_negatives(int *a, size_t n)
{
    double sum = 0;
    int count = 0;

    for (size_t i = 0; i < n; i++)
        if (a[i] < 0)
        {
            sum += a[i];
            count++;
        }

    if (count == 0)
        return 1.0;

    return sum / count;
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

    double average = average_of_negatives(a, n);

    if (average > 0)
    {
        printf("No negative values in the array.");
        return NO_NEG_VALUES;
    }

    printf("The arithmetic mean of the negative values in the array: %.6f", average);
    return OK;
}
