#include "my_string.h"

#define OK 0
#define STR_INPUT_ERR 1
#define STR_LEN_ERR 2
#define INCORRECT_WORD_ERR 3
#define EMPTY_STR_ERR 4

int main(void)
{
    char s1[STR_MAX_LEN + 1];
    char s2[STR_MAX_LEN + 1];
    char buff[STR_MAX_LEN + 2];
    word_array_t words1;
    word_array_t words2;
    size_t n1, n2;

    printf("Please, enter first string: ");
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
    strcpy(s1, buff);

    printf("Please, enter second string: ");
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
    strcpy(s2, buff);

    if (strlen(s1) == 0)
    {
        printf("Error. Input string is empty.");
        return EMPTY_STR_ERR;
    }

    n1 = split(words1, s1, WORD_MAX_LEN, STR_MAX_LEN / 2);
    if (n1 == 0)
    {
        printf("Error. Incorrect word in the string.");
        return INCORRECT_WORD_ERR;
    }

    n2 = split(words2, s2, WORD_MAX_LEN, STR_MAX_LEN / 2);
    if (n2 == 0)
    {
        printf("Error. Incorrect word in the string.");
        return INCORRECT_WORD_ERR;
    }

    printf("Result: ");
    check_words_intersection(words1, words2, n1, n2);

    return OK;
}
