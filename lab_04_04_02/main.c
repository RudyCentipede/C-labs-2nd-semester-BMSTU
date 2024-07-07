#include "my_string.h"

#define OK 0
#define STR_INPUT_ERR 1
#define STR_LEN_ERR 2

int main(void)
{
    char s[STR_MAX_LEN + 1];
    char buff[STR_MAX_LEN + 2];
    word_array_t words;
    size_t n;

    if (fgets(buff, STR_MAX_LEN + 2, stdin) == NULL)
        return STR_INPUT_ERR;


    buff[strcspn(buff, "\n")] = '\0';

    if (strlen(buff) && strlen(buff) > STR_MAX_LEN)
        return STR_LEN_ERR;

    strcpy(s, buff);

    if (trim(s, STR_MAX_LEN) == 0)
    {
        printf("NO");
        return OK;
    }

    n = split(words, s, WORD_MAX_LEN, WORD_AMOUNT_MAX);

    if (n == 3 && is_date(words))
        printf("YES");
    else
        printf("NO");

    return OK;
}
