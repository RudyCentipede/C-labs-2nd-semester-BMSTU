#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>

#define STR_MAX_LEN 1000000
#define WORD_MAX_LEN 16

typedef char word_array_t [STR_MAX_LEN / 2 + 1][WORD_MAX_LEN + 1];


size_t input_string_until(char s[]);
size_t split(word_array_t words, char s[], size_t len_max, size_t amount_max);
void print_lowercase_words(word_array_t words, size_t n);
bool is_contains_uppercase(char s[]);

#endif //MY_STRING_H
