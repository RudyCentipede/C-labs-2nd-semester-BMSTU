/*
  Выбранный целочисленный тип: int
  Алгоритм сортировки: сортировка пузырьком
  Направление упорядочивания: по возрастанию
*/
#include "file.h"
#include <string.h>

#define OK 0
#define ARGS_ERR 1
#define FILEPATH_ERR 2
#define FILE_WORK_ERR 3

int main(int argc, char **argv)
{
    if (argc == 4 && strcmp(argv[1], "c") == 0)
    {
        FILE *f = fopen(argv[3], "wb");
        fill_bin_rand_nums(f, atoi(argv[2]));
        fclose(f);
    }
    else if (argc == 3 && strcmp(argv[1], "p") == 0)
    {
        FILE *f = fopen(argv[2], "rb");
        if (f == NULL)
            return FILEPATH_ERR;


        if (print_bin_nums(f) <= 0)
        {
            fclose(f);
            return FILE_WORK_ERR;
        }
        fclose(f);
    }
    else if (argc == 3 && strcmp(argv[1], "s") == 0)
    {
        FILE *f = fopen(argv[2], "rb+");
        if (f == NULL)
            return FILEPATH_ERR;


        if (sort(f) <= 0)
        {
            fclose(f);
            return FILE_WORK_ERR;
        }
        fclose(f);
    }
    else if (argc == 4 && strcmp(argv[1], "import") == 0)
    {
        FILE *src = fopen(argv[2], "r");

        if (src == NULL)
            return FILEPATH_ERR;


        FILE *dst = fopen(argv[3], "wb");

        if (dst == NULL)
        {
            fclose(src);
            return FILEPATH_ERR;
        }

        txt_to_bin(src, dst);
        fclose(src);
        fclose(dst);
    }
    else if (argc == 4 && strcmp(argv[1], "export") == 0)
    {
        FILE *src = fopen(argv[2], "rb");

        if (src == NULL)
            return FILEPATH_ERR;


        FILE *dst = fopen(argv[3], "w");

        if (dst == NULL)
        {
            fclose(src);
            return FILEPATH_ERR;
        }

        if (bin_to_txt(src, dst) <= 0)
        {
            fclose(src);
            fclose(dst);
            return FILE_WORK_ERR;
        }

        fclose(src);
        fclose(dst);
    }
    else
        return ARGS_ERR;

    return OK;
}
