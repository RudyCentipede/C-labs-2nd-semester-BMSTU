#include <stdio.h>
#include <limits.h>

#define OK 0
#define INPUT_ERR 1
#define OVERFLOW 2

int fibonacci(int n)
{
    int fib1 = 1, fib2 = 1, tmp;

    for (int i = 1 ; i < n ; i++)
    {
        tmp = fib2;
        if ((fib1 > 0 && INT_MAX - fib1 < fib2) || (fib1 < 0 && INT_MIN - fib1 > fib2))
            return -1;
        else
        {
            fib2 = fib1 + fib2;
            fib1 = tmp;
        }
    }
    return fib1;
}

int main(void)
{
    int n;

    printf("Please, enter number: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Input error. Please, enter a positive integer.");
        return INPUT_ERR;
    }

    if (n == 0)
    {
        printf("Result: %d", 0);
        return OK;
    }

    int result = fibonacci(n);

    if (result == -1)
    {
        printf("Overflow for integer was detected. Program was prematurely terminated.");
        return OVERFLOW;
    }

    printf("Result: %d", result);
    return OK;
}
