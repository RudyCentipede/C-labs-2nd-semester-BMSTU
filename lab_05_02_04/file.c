#include "file.h"

int file_min(FILE *f, double *min)
{
    double num;
    if (fscanf(f, "%lf", min) == 1)
    {
        while (fscanf(f, "%lf", &num) == 1)
            if (num < *min)
                *min = num;
        return 0;
    }
    return 1;
}

int file_max(FILE *f, double *max)
{
    double num;
    if (fscanf(f, "%lf", max) == 1)
    {
        while (fscanf(f, "%lf", &num) == 1)
            if (num > *max)
                *max = num;
        return 0;
    }
    return 1;
}

int file_average_between(FILE *f, double min, double max, double *avg)
{
    double sum = 0;
    double num;
    int i = 0;

    while (fscanf(f, "%lf", &num) == 1 && i == 0)
    {
        if (fabs(num - min) < EPS || fabs(num - max) < EPS)
            while (fscanf(f, "%lf", &num) == 1 && fabs(num - min) >= EPS && fabs(num - max) >= EPS)
            {
                sum += num;
                i++;
            }
    }
    if (i == 0)
        return 1;

    *avg = sum / i;

    return 0;
}
