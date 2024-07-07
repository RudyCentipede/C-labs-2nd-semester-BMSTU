#include <stdio.h>

#define OK 0
#define N_INPUT_ERR 1
#define EL_INPUT_ERR 2

#define NMAX 10

int input_array_using_pointers(int *pa, int *pb)
{
    for (int *pcur = pa; pcur < pb; pcur++)
        if (scanf("%d", pcur) != 1)
            return EL_INPUT_ERR;

    return OK;
}

int count_same_elements(int *start, int *end)
{
    int count = 1;
    for (int *j = start; j < end; j++)
        if (*j == *end)
            count++;

    return count;
}

int count_of_unique(int *start, int *end)
{
    int count = 0;

    for (int *i = start; i < end; i++)
        if (count_same_elements(start, i) == 1)
            count++;

    return count;
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

    int *pa = a;
    int *pb = a + n;

    printf("Please, enter elements of array: ");

    if (input_array_using_pointers(pa, pb) != 0)
    {
        printf("Incorrect input of element.");
        return EL_INPUT_ERR;
    }

    int count = count_of_unique(pa, pb);

    printf("Count of unique numbers in the array: %d", count);
    return OK;
}
