#include "primes.h"

bool is_prime(int num)
{
    int a = num;
    int cnt = 0;
    for (int i = 2; i < a / 2 + 1; i++)
        if (a % i == 0)
            cnt++;
    return cnt == 0 && num > 1;
}
