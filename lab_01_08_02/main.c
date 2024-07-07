#include <stdio.h>
#include <inttypes.h>

#define OK 0
#define A_INPUT_ERR 1
#define N_INPUT_ERR 2

static void shift_and_convert(uint32_t a, int n)
{
    uint32_t mask = 1U << 31;
    a = a << n | a >> (32 - n);

    for (int i = 0; i < 32; i++)
    {
        if (a & mask)
            printf("1");
        else
            printf("0");

        a <<= 1;
    }
}

int main(void)
{
    uint32_t a;
    int n;

    printf("Please, enter integer A: ");
    if (scanf("%" SCNu32, &a) != 1)
    {
        printf("Error: Invalid input for integer.");
        return A_INPUT_ERR;
    }

    printf("Please, enter the number of shifts: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Error: number of shifts has to be a positive number.");
        return N_INPUT_ERR;
    }

    printf("Result: ");
    shift_and_convert(a, n);
    return OK;
}
