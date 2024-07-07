#ifndef PRODUCT_H__
#define PRODUCT_H__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

#define NAME_MAX 31
#define PRODUCER_MAX 16

typedef struct
{
    char name[NAME_MAX];
    char producer[PRODUCER_MAX];
    uint32_t price;
    uint32_t count;
} product_t;

int file_size(FILE *f, size_t *count_products);
int scan_str(char str[], size_t n, FILE *f);
int fscan_product(FILE *f, product_t *product);
void print_product(FILE *f, product_t product);
int get_product_by_pos(FILE *f, long pos, product_t *product);
int put_product_by_pos(FILE *f, long pos, product_t *product);
int copy(FILE *src, FILE *dst);
bool is_greater(product_t product1, product_t product2);
int sort_products(FILE *f);
int print_prods_end_substr(FILE *f, char sub_str[]);
int add_product(FILE *f, product_t *product);
int txt_to_bin(FILE *src, FILE *dst);
int bin_to_txt(FILE *src, FILE *dst);

#endif // PRODUCT_H__
