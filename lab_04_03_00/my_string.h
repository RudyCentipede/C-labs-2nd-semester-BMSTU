#ifndef MY_STRING_H__
#define MY_STRING_H__

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#define STR_MAX_LEN 256
#define WORD_MAX_LEN 16

typedef char word_array_t [STR_MAX_LEN / 2 + 1][WORD_MAX_LEN + 1];

size_t split(word_array_t words, char s[], size_t len_max, size_t amount_max);
size_t make_new_string(char new_s[], word_array_t words, size_t n);
size_t insert_word(char s[], char word[], size_t len);
size_t delete_letters_equal_first(char word[]);

#endif // MY_STRING_H__
