#include <stdio.h>

#define OK 0
#define INPUT_ERR 1

int main(void)
{
    int sec;
    int minute;
    int hour;

    printf("Please, enter the number of seconds: ");

    if (scanf("%d", &sec) != 1 || sec < 0)
    {
        printf("Error: Invalid input");
        return INPUT_ERR;
    }

    hour = sec / (60 * 60);
    sec = sec - hour * 60 * 60;
    minute = sec / 60;
    sec = sec - minute * 60;

    printf(" %d hours %d minutes %d seconds ", hour, minute, sec);
    return OK;
}
