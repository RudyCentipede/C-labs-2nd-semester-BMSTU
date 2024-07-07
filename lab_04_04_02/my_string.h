#ifndef MY_STRING_H__
#define MY_STRING_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_MAX_LEN 256
#define WORD_MAX_LEN 16
#define WORD_AMOUNT_MAX 3

typedef char word_array_t [WORD_AMOUNT_MAX][WORD_MAX_LEN + 1];

size_t trim(char s[], size_t nmax);
size_t split(word_array_t words, char s[], size_t len_max, size_t amount_max);
bool is_date(word_array_t words);
bool is_year_correct(char year[]);
bool is_month_correct(char month[], size_t i);
bool is_day_correct(char day[], size_t month, char year[]);
bool is_leap(int year);

#endif // MY_STRING_H__
