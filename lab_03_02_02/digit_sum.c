#include "digit_sum.h"

int digit_sum(int a)
{
    int sum = 0;
    a = abs(a);
    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}
