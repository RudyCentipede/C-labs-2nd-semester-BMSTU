#ifndef FILE_H__
#define FILE_H__

#include <stdio.h>
#include <math.h>

#define EPS 1e-8

int file_min(FILE *f, double *min);
int file_max(FILE *f, double *max);
int file_average_between(FILE *f, double min, double max, double *avg);

#endif //FILE_H__
