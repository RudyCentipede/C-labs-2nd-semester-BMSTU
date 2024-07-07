#ifndef FILE_H__
#define FILE_H__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int put_number_by_pos(FILE *f, long pos, int num);
int get_number_by_pos(FILE *f, long pos, int *num);
void fill_bin_rand_nums(FILE *f, int n);
int print_bin_nums(FILE *f);
int sort(FILE *f);
void txt_to_bin(FILE *src, FILE *dst);
int bin_to_txt(FILE *src, FILE *dst);
int file_size(FILE *f);

#endif //FILE_H__
