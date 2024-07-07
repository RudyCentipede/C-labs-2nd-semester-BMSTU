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

size_t delete_letters_equal_first(char word[])
{
    size_t i = 1;
    size_t j = 1;
    while (word[i] != '\0')
    {
        if (word[0] != word[i])
        {
            j++;
            word[j - 1] = word[i];
        }
        i++;
    }
    word[j] = '\0';
    return j;
}

size_t insert_word(char s[], char word[], size_t len)
{
    size_t j = len;

    for (size_t i = 0; word[i] != '\0'; i++)
    {
        j++;
        s[j - 1] = word[i];
    }
    s[j] = '\0';

    return j;
}

size_t make_new_string(char new_s[], word_array_t words, size_t n)
{
    size_t len = 0;
    char new_word[WORD_MAX_LEN];

    for (size_t i = n - 1; i > 0; i--)
    {
        if (strcmp(words[i - 1], words[n - 1]) != 0)
        {
            strcpy(new_word, words[i - 1]);
            delete_letters_equal_first(new_word);
            len = insert_word(new_s, " ", len);
            len = insert_word(new_s, new_word, len);
        }
    }

    return len;
}
