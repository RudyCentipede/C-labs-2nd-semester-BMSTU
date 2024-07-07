#include <stdio.h>
#include <math.h>

#define OK 0
#define X_INPUT_ERR 1
#define EPS_INPUT_ERR 2
#define ZERO_DIVISION_ERR 3

double s(double x, double eps)
{
    int n = 0;
    double result = x;
    double cur = x;

    while (fabs(cur) >= eps)
    {
        cur *= (pow(1 + 2 * n, 2) * x * x) / ((2 + 2 * n) * (3 + 2 * n));
        result += cur;
        n++;
    }

    return result;
}

int main(void)
{
    double x, eps;
    double f_value, s_value;
    double d_abs, d_rel;

    printf("Please, enter x: ");
    if (scanf("%lf", &x) != 1 || fabs(x) > 1)
    {
        printf("Input error. Please, enter x using numbers.");
        return X_INPUT_ERR;
    }

    printf("Please, enter eps: ");
    if (scanf("%lf", &eps) != 1 || eps < 0 || fabs(eps) < 1e-8 || eps > 1)
    {
        printf("Input error. Please, enter epsilone using numbers.");
        return EPS_INPUT_ERR;
    }

    f_value = asin(x);
    s_value = s(x, eps);
    d_abs = fabs(f_value - s_value);

    if (fabs(f_value) < 1e-8)
    {
        printf("Zero division error.");
        return ZERO_DIVISION_ERR;
    }

    d_rel = fabs(f_value - s_value) / fabs(f_value);

    printf("s(x): %.6f\n", s_value);
    printf("f(x): %.6f\n", f_value);
    printf("Absolute delta is: %.6f\n", d_abs);
    printf("Relative delta is: %.6f", d_rel);

    return OK;
}
