#include "product.h"
#include <string.h>

#define OK 0
#define FILEPATH_ERR 1
#define COPY_ERR 2
#define SORT_ERR 3
#define FIND_ERR 4
#define SCAN_ERR 5
#define INSERT_ERR 6
#define IMPORT_ERR 7
#define EXPORT_ERR 8
#define WRONG_ARGS 53

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    if (argc == 4 && strcmp(argv[1], "sb") == 0)
    {
        FILE *fsrc = fopen(argv[2], "rb");
        if (fsrc == NULL)
            return FILEPATH_ERR;
        FILE *fdst = fopen(argv[3], "wb+");
        if (fdst == NULL)
        {
            fclose(fsrc);
            return FILEPATH_ERR;
        }
        if (copy(fsrc, fdst))
        {
            fclose(fsrc);
            fclose(fdst);
            return COPY_ERR;
        }
        if (sort_products(fdst))
        {
            fclose(fsrc);
            fclose(fdst);
            return SORT_ERR;
        }
        fclose(fsrc);
        fclose(fdst);
    }
    else if (argc == 4 && strcmp(argv[1], "fb") == 0)
    {
        FILE *f = fopen(argv[2], "rb");
        if (f == NULL)
            return FILEPATH_ERR;
        if (print_prods_end_substr(f, argv[3]))
        {
            fclose(f);
            return FIND_ERR;
        }
        fclose(f);
    }
    else if (argc == 3 && strcmp(argv[1], "ab") == 0)
    {
        product_t product = { 0 };
        if (fscan_product(stdin, &product))
            return SCAN_ERR;
        FILE *f = fopen(argv[2], "rb+");
        if (f == NULL)
        {
            f = fopen(argv[2], "wb+");
            if (f == NULL)
                return FILEPATH_ERR;
        }
        if (add_product(f, &product))
        {
            fclose(f);
            return INSERT_ERR;
        }
        fclose(f);
    }
    else if (argc == 4 && strcmp(argv[1], "import") == 0)
    {
        FILE *fsrc = fopen(argv[2], "r");
        if (fsrc == NULL)
            return FILEPATH_ERR;
        FILE *fdst = fopen(argv[3], "wb");
        if (fdst == NULL)
        {
            fclose(fsrc);
            return FILEPATH_ERR;
        }
        if (txt_to_bin(fsrc, fdst))
        {
            fclose(fsrc);
            fclose(fdst);
            return IMPORT_ERR;
        }
        fclose(fsrc);
        fclose(fdst);
    }
    else if (argc == 4 && strcmp(argv[1], "export") == 0)
    {
        FILE *fsrc = fopen(argv[2], "rb");
        if (fsrc == NULL)
            return FILEPATH_ERR;
        FILE *fdst = fopen(argv[3], "w");
        if (fdst == NULL)
        {
            fclose(fsrc);
            return FILEPATH_ERR;
        }
        if (bin_to_txt(fsrc, fdst))
        {
            fclose(fsrc);
            fclose(fdst);
            return EXPORT_ERR;
        }
        fclose(fsrc);
        fclose(fdst);
    }
    else
        return WRONG_ARGS;

    return OK;
}
