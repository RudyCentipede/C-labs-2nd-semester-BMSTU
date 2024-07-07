#include <stdio.h>
#include "my_string.h"

#define OK 0
#define STR_INPUT_ERR 1
#define STR_LEN_ERR 2
#define INCORRECT_WORD_ERR 3
#define EMPTY_STR_ERR 4

int main(void)
{
    char s[STR_MAX_LEN + 1];
    char buff[STR_MAX_LEN + 2];
    word_array_t words;
    char new_s[STR_MAX_LEN + 1];
    size_t n, len;

    printf("Please, enter string: ");
    if (fgets(buff, STR_MAX_LEN + 2, stdin) == NULL)
    {
        printf("String input error.");
        return STR_INPUT_ERR;
    }

    buff[strcspn(buff, "\n")] = '\0';

    if (strlen(buff) > STR_MAX_LEN)
    {
        printf("Error. Length of input string is bigger than maximum.");
        return STR_LEN_ERR;
    }

    strcpy(s, buff);

    n = split(words, s, WORD_MAX_LEN, STR_MAX_LEN / 2);
    if (n == 0)
    {
        printf("Error. Incorrect word in the string.");
        return INCORRECT_WORD_ERR;
    }

    len = make_new_string(new_s, words, n);

    if (len == 0)
    {
        printf("Result string is empty.");
        return EMPTY_STR_ERR;
    }

    printf("Result:%s\n", new_s);

    return OK;
}
