#include "array.h"

int prod_elems(int a[], size_t n)
{
    int prod = 1;
    for (size_t i = 0; i < n; i++)
        prod *= a[i];
    return prod;
}

void copy_elems(int a[], int b[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        a[i] = b[i];
}
