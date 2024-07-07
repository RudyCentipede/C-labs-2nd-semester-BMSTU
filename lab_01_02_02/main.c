#include <stdio.h>
#include <math.h>

#define OK 0
#define A_INPUT_ERR 1
#define B_INPUT_ERR 2
#define C_INPUT_ERR 3

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    double side_ab, side_ac, side_bc;

    printf("Please, enter coordinates for A: ");

    if (scanf("%lf%lf", &xa, &ya) != 2)
    {
        printf("Error: Invalid input for coordinate");
        return A_INPUT_ERR;
    }

    printf("Please, enter coordinates for B: ");

    if (scanf("%lf%lf", &xb, &yb) != 2)
    {
        printf("Error: Invalid input for coordinate");
        return B_INPUT_ERR;
    }

    printf("Please, enter coordinates for C: ");

    if (scanf("%lf%lf", &xc, &yc) != 2)
    {
        printf("Error: Invalid input for coordinate");
        return C_INPUT_ERR;
    }

    //Calculate the length of each side
    side_ab = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    side_ac = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
    side_bc = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));

    double perimeter = side_ab + side_ac + side_bc;

    printf("Perimeter of this triangle is %.6f", perimeter);
    return OK;
}
