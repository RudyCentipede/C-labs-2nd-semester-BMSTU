#include "file.h"

int put_number_by_pos(FILE *f, long pos, int num)
{
    long cur_pos = ftell(f);
    if (cur_pos < 0)
        return 1;
    if (fseek(f, pos * (long)sizeof(int), SEEK_SET))
        return 1;
    if (fwrite(&num, sizeof(int), 1, f) != 1)
        return 1;
    if (fseek(f, cur_pos, SEEK_SET))
        return 1;
    return 0;
}

int get_number_by_pos(FILE *f, long pos, int *num)
{
    long cur_pos = ftell(f);
    if (cur_pos < 0)
        return 1;
    if (fseek(f, pos * (long)sizeof(int), SEEK_SET))
        return 1;
    if (fread(num, sizeof(int), 1, f) != 1)
        return 1;
    if (fseek(f, cur_pos, SEEK_SET))
        return 1;
    return 0;
}

int file_size(FILE *f)
{
    long pos = ftell(f);

    if (pos < 0)
        return -1;

    if (fseek(f, 0L, SEEK_END))
        return -1;

    long n = ftell(f);

    if (n <= 0)
        return -1;

    size_t count_numbers = (size_t)n / sizeof(int);
    if (count_numbers * sizeof(int) != (size_t)n)
        return -1;

    if (fseek(f, pos, SEEK_SET))
        return -1;

    return (int)count_numbers;
}


void fill_bin_rand_nums(FILE *f, int n)
{
    int num;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        num = rand();
        put_number_by_pos(f, i, num);
    }
}

int print_bin_nums(FILE *f)
{
    int num;
    int size = file_size(f);
    if (size > 0)
        for (int i = 0; i < size; i++)
        {
            if (get_number_by_pos(f, i, &num) != 0)
                return -1;
            printf("%d ", num);
        }

    return size;
}

int sort(FILE *f)
{
    int t1, t2;
    int size = file_size(f);
    if (size > 0)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - i - 1; j++)
            {
                if (get_number_by_pos(f, j, &t1) != 0)
                    return -1;
                if (get_number_by_pos(f, j + 1, &t2) != 0)
                    return -1;
                if (t1 > t2)
                {
                    if (put_number_by_pos(f, j, t2) != 0)
                        return -1;
                    if (put_number_by_pos(f, j + 1, t1) != 0)
                        return -1;
                }
            }

    return size;
}

void txt_to_bin(FILE *src, FILE *dst)
{
    int num;
    for (int i = 0; fscanf(src, "%d", &num) == 1; i++)
        put_number_by_pos(dst, i, num);
}

int bin_to_txt(FILE *src, FILE *dst)
{
    int num;
    int size = file_size(src);
    if (size > 0)
        for (int i = 0; i < size; i++)
        {
            get_number_by_pos(src, i, &num);
            fprintf(dst, "%d ", num);
        }

    return size;
}
