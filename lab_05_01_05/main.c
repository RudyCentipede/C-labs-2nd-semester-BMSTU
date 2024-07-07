#include <stdio.h>
#include "file.h"

int main(void)
{
    int max;
    printf("Please, enter numbers: ");
    int code = process(stdin, &max);

    if (code != 0)
    {
        printf("An error occurred during the process.");
        return code;
    }

    printf("Result: %d", max);
    return 0;
}
