#include "array.h"
#include "digit_sum.h"

void copy_elems(int a[], int b[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        a[i] = b[i];
}

int count_odd_digits_sum_elems(int a[], size_t n)
{
    int cnt = 0;
    for (size_t i = 0; i < n; i++)
        if (digit_sum(a[i]) % 2 != 0)
            cnt++;

    return cnt;
}
