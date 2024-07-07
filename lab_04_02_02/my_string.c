#include "my_string.h"

size_t split(word_array_t words, char s[], size_t len_max, size_t amount_max)
{
    size_t n = 0;
    size_t j = 0;
    char word[WORD_MAX_LEN];

    for (size_t i = 0; s[i] != '\0'; i++)
        if (!ispunct(s[i]) && !isspace(s[i]))
        {
            if (j + 1 == len_max)
                return 0;
            j++;
            word[j - 1] = s[i];
        }
        else
        {
            if (n >= amount_max)
                return 0;

            if (j != 0)
            {
                n++;
                word[j] = '\0';
                strcpy(words[n - 1], word);
            }
            j = 0;
        }
    if (j == len_max || n >= amount_max)
        return 0;

    word[j] = '\0';

    if (j != 0)
    {
        n++;
        strcpy(words[n - 1], word);
    }
    return n;
}

int count_occurrence_before(char word[], word_array_t words, size_t n)
{
    int cnt = 0;
    for (size_t i = n; i > 0; i--)
        if (strcmp(word, words[i - 1]) == 0)
            cnt++;
    return cnt;
}

void check_words_intersection(word_array_t words1, word_array_t words2, size_t n1, size_t n2)
{
    for (size_t i = 0; i < n1; i++)
    {
        bool is_word_intersect = false;
        if (count_occurrence_before(words1[i], words1, i) == 0)
        {
            for (size_t j = 0; j < n2; j++)
                if (strcmp(words1[i], words2[j]) == 0)
                    is_word_intersect = true;

            if (is_word_intersect)
                printf("%s yes\n", words1[i]);
            else
                printf("%s no\n", words1[i]);
        }
    }
}
