#include <stdio.h>

#define OK 0
#define ARRAY_SIZE_ERR 1
#define OVERFLOW 100

#define NMAX 10

int input_array_until_error(int *a, size_t *n, size_t n_max)
{
    int el;
    while (scanf("%d", &el) == 1)
    {
        if (*n == n_max)
            return OVERFLOW;

        (*n)++;
        a[*n - 1] = el;
    }
    return OK;
}

void selection_sort(int *a, size_t n)
{
    size_t min_pos;
    for (size_t i = 0; i < n; i++)
    {
        min_pos = i;
        for (size_t j = i + 1; j < n; j++)
            if (a[min_pos] > a[j])
                min_pos = j;

        int tmp = a[min_pos];
        a[min_pos] = a[i];
        a[i] = tmp;
    }
}

void print_array(int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main(void)
{
    int a[NMAX];
    size_t n = 0;

    printf("Please, enter elements of array: ");

    int return_code = input_array_until_error(a, &n, NMAX);
    if (n == 0)
    {
        printf("Array is empty.");
        return ARRAY_SIZE_ERR;
    }

    selection_sort(a, n);

    printf("Sorted array: ");
    print_array(a, n);
    return return_code;
}
