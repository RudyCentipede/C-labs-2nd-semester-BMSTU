#include "product.h"

int get_product_by_pos(FILE *f, long pos, product_t *product)
{
    long cur_pos = ftell(f);
    if (cur_pos < 0)
        return 1;
    if (fseek(f, pos * (long)sizeof(product_t), SEEK_SET))
        return 1;
    if (fread(product, sizeof(product_t), 1, f) != 1)
        return 1;
    return fseek(f, cur_pos, SEEK_SET);
}

int put_product_by_pos(FILE *f, long pos, product_t *product)
{
    long cur_pos = ftell(f);
    if (cur_pos < 0)
        return 1;
    if (fseek(f, pos * (long)sizeof(product_t), SEEK_SET))
        return 1;
    if (fwrite(product, sizeof(product_t), 1, f) != 1)
        return 1;
    return fseek(f, cur_pos, SEEK_SET);
}

int file_size(FILE *f, size_t *count_products)
{
    long pos = ftell(f);
    if (pos < 0)
        return 1;
    if (fseek(f, 0L, SEEK_END))
        return 1;
    long size = ftell(f);
    if (size < 0)
        return 1;

    *count_products = (size_t)size / sizeof(product_t);
    if (*count_products * sizeof(product_t) != (size_t)size)
        return 1;

    return fseek(f, pos, SEEK_SET);
}

int scan_str(char str[], size_t n, FILE *f)
{
    if (n >= NAME_MAX + 1)
        return 1;
    char buf[NAME_MAX + 1];
    if (!fgets(buf, (int)(n + 1), f))
        return 1;

    size_t len = strlen(buf);
    if (buf[len - 1] == '\n')
    {
        len--;
        buf[len] = '\0';
    }

    if (len == 0 || len >= n)
        return 1;

    strncpy(str, buf, n);

    return 0;
}

int fscan_product(FILE *f, product_t *product)
{
    if (scan_str(product->name, NAME_MAX, f))
        return 1;
    if (scan_str(product->producer, PRODUCER_MAX, f))
        return 1;
    if (!fscanf(f, "%"SCNu32"", &product->price))
        return 1;
    if (!fscanf(f, "%"SCNu32"", &product->count))
        return 1;

    fscanf(f, "\n");

    return 0;
}

void print_product(FILE *f, product_t product)
{
    fprintf(f, "%s\n", product.name);
    fprintf(f, "%s\n", product.producer);
    fprintf(f, "%"PRIu32"\n", product.price);
    fprintf(f, "%"PRIu32"\n", product.count);
}

int copy(FILE *src, FILE *dst)
{
    product_t product = { 0 };
    size_t count_products = 0;
    if (file_size(src, &count_products))
        return 1;

    for (size_t i = 0; i < count_products; i++)
    {
        if (get_product_by_pos(src, (long)i, &product))
            return 1;
        if (put_product_by_pos(dst, (long)i, &product))
            return 1;
    }

    return 0;
}

bool is_greater(product_t product1, product_t product2)
{
    return (product1.price > product2.price) || (product1.price == product2.price && product1.count > product2.count);
}

int sort_products(FILE *f)
{
    product_t product1 = { 0 }, product2 = { 0 };
    int end = 0;
    size_t count_products = 0;
    if (file_size(f, &count_products))
        return 1;

    for (size_t i = 0; i < count_products - 1 && !end; i++)
    {
        end = 1;
        for (size_t j = 0; j < count_products - 1 - i; j++)
        {
            if (get_product_by_pos(f, (long)j, &product1))
                return 1;
            if (get_product_by_pos(f, (long)(j + 1), &product2))
                return 1;
            if (is_greater(product2, product1))
            {
                end = 0;
                if (put_product_by_pos(f, (long)j, &product2))
                    return 1;
                if (put_product_by_pos(f, (long)(j + 1), &product1))
                    return 1;
            }
        }
    }

    return 0;
}

int print_prods_end_substr(FILE *f, char sub_str[])
{
    size_t len_sb = strlen(sub_str);
    if (len_sb == 0)
        return 1;
    product_t product = { 0 };
    size_t count_products = 0;
    if (file_size(f, &count_products))
        return 1;

    int rc = 1;
    for (size_t i = 0; i < count_products; i++)
    {
        if (get_product_by_pos(f, (long)i, &product))
            return 1;
        size_t len_name = strlen(product.name);
        if (len_name >= len_sb)
        {
            size_t len_dif = len_name - len_sb;
            if (strcmp(product.name + len_dif, sub_str) == 0)
            {
                rc = 0;
                print_product(stdout, product);
            }
        }
    }

    return rc;
}

int add_product(FILE *f, product_t *product)
{
    product_t cur_product = { 0 };
    size_t count_products = 0;
    if (file_size(f, &count_products))
        return 1;
    if (count_products == 0)
        return put_product_by_pos(f, 0, product);

    size_t i;
    for (i = count_products - 1; i > 0; i--)
    {
        if (get_product_by_pos(f, (long)i, &cur_product))
            return 1;
        if (is_greater(cur_product, *product))
            return put_product_by_pos(f, (long)(i + 1), product);
        else if (put_product_by_pos(f, (long)(i + 1), &cur_product))
            return 1;
    }
    if (get_product_by_pos(f, (long)i, &cur_product))
        return 1;
    if (is_greater(cur_product, *product))
        return put_product_by_pos(f, (long)(i + 1), product);
    else
    {
        if (put_product_by_pos(f, (long)(i + 1), &cur_product))
            return 1;
        return put_product_by_pos(f, (long)i, product);
    }
}

int txt_to_bin(FILE *src, FILE *dst)
{
    product_t product = { 0 };
    for (size_t i = 0; !fscan_product(src, &product); i++)
        if (put_product_by_pos(dst, (long)i, &product))
            return 1;
    return 0;
}

int bin_to_txt(FILE *src, FILE *dst)
{
    product_t product = { 0 };
    size_t count_products = 0;
    if (file_size(src, &count_products))
        return 1;

    for (size_t i = 0; i < count_products; i++)
    {
        if (get_product_by_pos(src, (long)i, &product))
            return 1;
        print_product(dst, product);
    }

    return 0;
}
