#include <stdio.h>
#include "file.h"

#define OK 0
#define ARGS_ERR 1
#define FILEPATH_ERR 2
#define EMPTY_FILE_ERR 3
#define NO_NUMS_BETWEEN_ERR 4

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error. There must be one argument.");
        return ARGS_ERR;
    }

    FILE *f;
    double min, max, avg;

    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Error. There is no such file.");
        return FILEPATH_ERR;
    }

    if (file_min(f, &min) != 0)
    {
        printf("Error. No data in the file.");
        return EMPTY_FILE_ERR;
    }

    rewind(f);

    file_max(f, &max);

    rewind(f);

    if (file_average_between(f, min, max, &avg) != 0)
    {
        printf("Error. There is no numbers between minimum and maximum.");
        return NO_NUMS_BETWEEN_ERR;
    }

    fclose(f);
    printf("%.6lf", avg);
    return OK;
}
