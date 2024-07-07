#include <stdio.h>
#include <math.h>

#define OK 0
#define X_INPUT_ERR 1
#define EL_INPUT_ERR 2

void print_line(int n, double el, double s)
{
    printf("%d %-7.2lf %-12.2f\n", n, el, s);
}

double f(double x)
{
    return sin(x) * x;
}

double s(double x, double eps)
{
    int n = 1;
    int i = 2;
    double cur = pow(x, 5) / 6;
    double result = cur;
    print_line(n, cur, result);

    while (fabs(cur) >= eps)
    {
        cur *= -(x * x) / (i + 2);
        result += cur;
        i++;
        n++;
        print_line(n, cur, result);
    }
    return result;
}

int main(void)
{
    double x, eps;
    double f_value, s_value;
    printf("Please, enter x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Error. Invalid input for x.");
        return X_INPUT_ERR;
    }

    printf("Please, enter eps: ");
    if (scanf("%lf", &eps) != 1)
    {
        printf("Error. Invalid input for eps.");
        return EL_INPUT_ERR;
    }

    f_value = f(x);
    printf("N Element Current_summ\n");
    s_value = s(x, eps);

    printf("Value of f(x): %-.2lf\n", f_value);
    printf("Value of s(x): %g", s_value);

    return OK;
}

