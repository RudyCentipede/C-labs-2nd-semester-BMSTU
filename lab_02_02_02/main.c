#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define N_INPUT_ERR 1
#define EL_INPUT_ERR 2
#define NO_MATCH_VALUES 3

#define NMAX 10

int input_array(int *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return 1;
    return 0;
}

bool is_same_start_and_end(int num)
{
    if (num < 0)
        num *= -1;

    int start_digit = num % 10;
    int end_digit = num / 10;

    while (end_digit >= 10)
        end_digit /= 10;

    return start_digit == end_digit || (num >= 0 && num < 10);
}

size_t copy_same_start_and_ends(int *b, int *a, size_t n)
{
    size_t j = 0;
    for (size_t i = 0; i < n; i++)
        if (is_same_start_and_end(a[i]))
        {
            j++;
            b[j - 1] = a[i];
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

    int b[NMAX];
    size_t b_len = copy_same_start_and_ends(b, a, n);

    if (b_len == 0)
    {
        printf("Error. No matching values.");
        return NO_MATCH_VALUES;
    }

    printf("New array: ");
    print_array(b, b_len);

    return OK;
}
