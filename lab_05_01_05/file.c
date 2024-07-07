#include "file.h"

int process(FILE *f, int *max)
{
    int cur, next;
    int count = 1;

    if (fscanf(f, "%d", &cur) != 1)
        return EMPTY_FILE_ERR;

    *max = count;

    if (fscanf(f, "%d", &next) != 1)
        return 0;

    do
    {
        if (cur == next)
            count++;
        else
        {
            if (count > *max)
                *max = count;
            count = 1;
        }

        cur = next;
    }
    while (fscanf(f, "%d", &next) == 1);

    if (count > *max)
        *max = count;

    return 0;
}
