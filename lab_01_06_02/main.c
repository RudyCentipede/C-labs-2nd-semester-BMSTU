#include <stdio.h>
#include <math.h>

#define OK 0
#define A_INPUT_ERR 1
#define B_INPUT_ERR 2
#define C_INPUT_ERR 3
#define POINT_INPUT_ERR 4
#define NOT_TRIANGLE_ERR 5

double product_of_vectors(double x1, double y1, double x2, double y2, double x0, double y0)
{
    return (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
}

int main(void)
{
    double xa, ya, xb, yb, xc, yc, xp, yp;
    double f, s, t;                       // first, second and third products of vectors
    double eps = 1e-8;

    printf("Please, enter coordinates for A: ");
    if (scanf("%lf%lf", &xa, &ya) != 2)
    {
        printf("Input error. Please, enter coordinates using numbers.");
        return A_INPUT_ERR;
    }

    printf("Please, enter coordinates for B: ");
    if (scanf("%lf%lf", &xb, &yb) != 2)
    {
        printf("Input error. Please, enter coordinates using numbers.");
        return B_INPUT_ERR;
    }

    printf("Please, enter coordinates for C: ");
    if (scanf("%lf%lf", &xc, &yc) != 2)
    {
        printf("Input error. Please, enter coordinates using numbers.");
        return C_INPUT_ERR;
    }

    printf("Please, enter coordinates for Point: ");
    if (scanf("%lf%lf", &xp, &yp) != 2)
    {
        printf("Input error. Please, enter coordinates using numbers.");
        return POINT_INPUT_ERR;
    }

    // check if it's not a triangle
    if (fabs(product_of_vectors(xa, ya, xb, yb, xc, yc)) < eps)
    {
        printf("Input error. It is not a triangle, because points lie on straight line.");
        return NOT_TRIANGLE_ERR;
    }

    f = product_of_vectors(xa, ya, xb, yb, xp, yp);
    s = product_of_vectors(xb, yb, xc, yc, xp, yp);
    t = product_of_vectors(xc, yc, xa, ya, xp, yp);

    if ((f > 0 && s > 0 && t > 0) || (f < 0 && s < 0 && t < 0))
        printf("%d", 0);
    else if (fabs(f) < eps || fabs(s) < eps || fabs(t) < eps)
        printf("%d", 1);
    else
        printf("%d", 2);

    return OK;
}
