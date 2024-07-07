#include "my_string.h"

size_t input_string_until(char s[])
{
    bool flag = true;
    word_array_t words;
    while (flag)
    {
        if (fgets(s, STR_MAX_LEN + 1, stdin) == NULL)
            return 0;

        if (strncmp(s, "11111", 5) == 0)
            flag = false;

        if (flag)
        {
            size_t n = split(words, s, WORD_MAX_LEN, STR_MAX_LEN / 2);
            if (n == 0)
                return 0;
            print_lowercase_words(words, n);
        }

    }
    return strlen(s);
}

size_t split(word_array_t words, char s[], size_t len_max, size_t amount_max)
{
    size_t n = 0;
    size_t j = 0;
    char word[WORD_MAX_LEN];

    for (size_t i = 0; s[i] != '\0'; i++)
        if (s[i] != '\t')
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

bool is_contains_uppercase(char s[])
{
    bool res = false;
    char buff[STR_MAX_LEN + 1];
    strcpy(buff, s);
    for (size_t i = 0; buff[i] != '\0'; i++)
        if (s[i] != tolower(buff[i]))
            res = true;
    return res;
}

void print_lowercase_words(word_array_t words, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (!is_contains_uppercase(words[i]))
            printf("%s ", words[i]);
    }

}