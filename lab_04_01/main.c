#include <string.h>
#include "my_string.h"

#define STR_MAX_LEN 256

int main(void)
{
    int fails = 0;

    // my_strpbrk
    {
        char s1[STR_MAX_LEN] = "Herr3yo";
        char s2[STR_MAX_LEN] = "12yo3";

        if (strpbrk(s1, s2) != my_strpbrk(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "";
        char s2[STR_MAX_LEN] = "";

        if (strpbrk(s1, s2) != my_strpbrk(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "";
        char s2[STR_MAX_LEN] = "12yo3";

        if (strpbrk(s1, s2) != my_strpbrk(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "Herr3yo";
        char s2[STR_MAX_LEN] = "";

        if (strpbrk(s1, s2) != my_strpbrk(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "Herr3yo";
        char s2[STR_MAX_LEN] = "8pq";

        if (strpbrk(s1, s2) != my_strpbrk(s1, s2))
            fails++;
    }


    // my_strspn
    {
        char s1[STR_MAX_LEN] = "2fowwodj";
        char s2[STR_MAX_LEN] = "w803";

        if (strspn(s1, s2) != my_strspn(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "";
        char s2[STR_MAX_LEN] = "";

        if (strspn(s1, s2) != my_strspn(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "2";
        char s2[STR_MAX_LEN] = "";

        if (strspn(s1, s2) != my_strspn(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "";
        char s2[STR_MAX_LEN] = "22803";

        if (strspn(s1, s2) != my_strspn(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "2";
        char s2[STR_MAX_LEN] = "803";

        if (strspn(s1, s2) != my_strspn(s1, s2))
            fails++;
    }


    // my_strcspn
    {
        char s1[STR_MAX_LEN] = "0123456789";
        char s2[STR_MAX_LEN] = "22803";

        if (strcspn(s1, s2) != my_strcspn(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "";
        char s2[STR_MAX_LEN] = "";

        if (strcspn(s1, s2) != my_strcspn(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "";
        char s2[STR_MAX_LEN] = "22803";

        if (strcspn(s1, s2) != my_strcspn(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "0123456789";
        char s2[STR_MAX_LEN] = "";

        if (strcspn(s1, s2) != my_strcspn(s1, s2))
            fails++;
    }

    {
        char s1[STR_MAX_LEN] = "0123456789";
        char s2[STR_MAX_LEN] = "ha";

        if (strcspn(s1, s2) != my_strcspn(s1, s2))
            fails++;
    }

    // my_strchr
    {
        char s[STR_MAX_LEN] = "012N345N6789";
        int c = '\0';

        if (strchr(s, c) != my_strchr(s, c))
            fails++;
    }

    {
        char s[STR_MAX_LEN] = "012N345N6789";
        int c = 'N';

        if (strchr(s, c) != my_strchr(s, c))
            fails++;
    }

    {
        char s[STR_MAX_LEN] = "";
        int c = '2';

        if (strchr(s, c) != my_strchr(s, c))
            fails++;
    }

    {
        char s[STR_MAX_LEN] = "01N345N6789";
        int c = ' ';

        if (strchr(s, c) != my_strchr(s, c))
            fails++;
    }

    {
        char s[STR_MAX_LEN] = "012N3 45 N6789";
        int c = ' ';

        if (strchr(s, c) != my_strchr(s, c))
            fails++;
    }

    // my_strrchr
    {
        char s[STR_MAX_LEN] = "012N345N6789";
        int c = '\0';

        if (strrchr(s, c) != my_strrchr(s, c))
            fails++;
    }

    {
        char s[STR_MAX_LEN] = "012N345N6789";
        int c = 'N';

        if (strrchr(s, c) != my_strrchr(s, c))
            fails++;
    }

    {
        char s[STR_MAX_LEN] = "";
        int c = '2';

        if (strrchr(s, c) != my_strrchr(s, c))
            fails++;
    }

    {
        char s[STR_MAX_LEN] = "012N345N6789";
        int c = ' ';

        if (strrchr(s, c) != my_strrchr(s, c))
            fails++;
    }

    {
        char s[STR_MAX_LEN] = "?012N3?5N6?89";
        int c = '?';

        if (strrchr(s, c) != my_strrchr(s, c))
            fails++;
    }

    printf("The number of failed tests: %d", fails);
    return 0;
}
