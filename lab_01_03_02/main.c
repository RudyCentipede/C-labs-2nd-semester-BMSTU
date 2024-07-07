#include <stdio.h>

#define OK 0
#define FIRST_RESISTOR_INPUT_ERROR 1
#define SECOND_RESISTOR_INPUT_ERROR 2
#define THIRD_RESISTOR_INPUT_ERROR 3
#define ZERO_DIVISION_ERR 4


int main(void)
{
    double r1, r2, r3;
    double r_total;
    double eps = 1e-8;

    printf("Please, enter resistance of first resistor: ");
    if (scanf("%lf", &r1) != 1 || r1 < 0)
    {
        printf("Error: Invalid input. Resistance is a positive number.");
        return FIRST_RESISTOR_INPUT_ERROR;
    }

    printf("Please, enter resistance of second resistor: ");
    if (scanf("%lf", &r2) != 1 || r2 < 0)
    {
        printf("Error: Invalid input. Resistance is a positive number.");
        return SECOND_RESISTOR_INPUT_ERROR;
    }

    printf("Please, enter resistance of third resistor: ");
    if (scanf("%lf", &r3) != 1 || r3 < 0)
    {
        printf("Error: Invalid input. Resistance is a positive number.");
        return THIRD_RESISTOR_INPUT_ERROR;
    }

    if ((r1 * r2) < eps && (r2 * r3) < eps && (r3 * r1) < eps)
    {
        printf("Error: Zero division.");
        return ZERO_DIVISION_ERR;
    }

    r_total = (r1 * r2 * r3) / (r1 * r2 + r2 * r3 + r3 * r1);
    printf("Equal resistance of circuit is %.6f", r_total);
    return OK;
}
