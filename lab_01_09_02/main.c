#include <stdio.h>
#include <math.h>

#define OK 0
#define INPUT_ERR 1

double read_until_negative(double x)
{
    double result = 0;
    int n = 1;
    while (x >= 0)
    {
        result += sqrt(x + n);
        n++;
        if (scanf("%lf", &x) != 1)
            return -1;
    }

    result /= (n - 1);
    return result;
}

int main(void)
{
    double x;
    double g;

    printf("Please, enter x: ");
    if (scanf("%lf", &x) != 1 || x < 0)
    {
        printf("Error: Invalid input.");
        return INPUT_ERR;
    }

    g = read_until_negative(x);

    if (g < 0)
    {
        printf("Error: Invalid input.");
        return INPUT_ERR;
    }

    printf("Result: %.6lf\n", g);

    return OK;
}
