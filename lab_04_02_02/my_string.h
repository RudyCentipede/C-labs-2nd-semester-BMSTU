#ifndef MY_STRING_H__
#define MY_STRING_H__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STR_MAX_LEN 256
#define WORD_MAX_LEN 16

typedef char word_array_t [STR_MAX_LEN / 2 + 1][WORD_MAX_LEN + 1];

size_t split(word_array_t words, char s[], size_t len_max, size_t amount_max);
void check_words_intersection(word_array_t words1, word_array_t words2, size_t n1, size_t n2);
int count_occurrence_before(char word[], word_array_t words, size_t n);

#endif // MY_STRING_H__
