#include "array.h"

void reverse_array(int a[], size_t n)
{
    int tmp;
    for (size_t i = 0; i < n / 2; i++)
    {
        tmp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = tmp;
    }
}

