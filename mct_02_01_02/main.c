#include <stdio.h>
#include "my_string.h"
#define OK 0

int main(void)
{
    char s[STR_MAX_LEN + 1];

    printf("Please, enter string: ");
    input_string_until(s);
    return OK;
}
