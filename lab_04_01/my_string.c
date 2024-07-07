#include "my_string.h"

char *my_strpbrk(const char *s1, const char *s2)
{
    for (size_t i = 0; s1[i] != '\0'; i++)
        for (size_t j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return (char *)&s1[i];
    return NULL;
}

size_t my_strspn(const char *s1, const char *s2)
{
    size_t len = 0;
    for (size_t i = 0; s1[i] != '\0'; i++)
    {
        bool flag = false;
        for (size_t j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                flag = true;
        if (!flag)
            return len;
        len++;
    }
    return len;
}

size_t my_strcspn(const char *s1, const char *s2)
{
    size_t len = 0;
    for (size_t i = 0; s1[i] != '\0'; i++)
    {
        bool flag = true;
        for (size_t j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                flag = false;
        if (!flag)
            return len;
        len++;
    }
    return len;
}

char *my_strchr(const char *s, int c)
{
    size_t i = 0;
    for (; s[i] != '\0'; i++)
        if (s[i] == c)
            return (char *)&s[i];
    if (c == '\0')
        return (char *)&s[i];
    return NULL;
}

char *my_strrchr(const char *s, int c)
{
    size_t i = 0;
    char *result = NULL;
    for (; s[i] != '\0'; i++)
        if (s[i] == c)
            result = (char *)&s[i];
    if (c == '\0')
        return (char *)&s[i];

    return result;
}
