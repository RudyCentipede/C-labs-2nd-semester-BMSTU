#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define OK 0;

#define NMAX 100

size_t input_array_until_not_pos(int *a, size_t n_max)
{
    int el;
    size_t i = 0;
    while (scanf("%d", &el) == 1 && i <= n_max && el > 0)
    {
        i++;
        a[i - 1] = el;
    }
    return i;
}

bool is_square(int a)
{
    return (int)sqrt(a) * (int)sqrt(a) == a;
}

size_t delete_squares(int *a, size_t n)
{
    int j = 0;
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
    int flag;
    do {
        int a[NMAX];
        printf("Please, enter array elements: ");
        size_t n = input_array_until_not_pos(a, NMAX);

        printf("Input array: ");
        print_array(a, n);

        n = delete_squares(a, n);

        printf("\nResult array: ");
        print_array(a, n);
        scanf("%d", &flag);
    }
    while (flag != -1);
    return OK;
}

