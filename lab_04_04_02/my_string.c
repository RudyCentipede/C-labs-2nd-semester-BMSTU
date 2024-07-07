#include "my_string.h"

static char *months[] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

size_t trim(char s[], size_t nmax)
{
    size_t start = 0;
    size_t j = 0;
    size_t end = strlen(s);

    while (start < nmax && isspace(s[start]))
        start++;
    while (end > start && end < nmax && (isspace(s[end]) || s[end] == '\0'))
        end--;

    if (end > nmax)
        return 0;

    for (size_t i = start; i <= end; i++)
    {
        if (j + 1 == nmax)
            return 0;
        j++;
        s[j - 1] = s[i];
    }

    if (j == nmax)
        return 0;

    s[j] = '\0';
    return j;
}

size_t split(word_array_t words, char s[], size_t len_max, size_t amount_max)
{
    size_t n = 0;
    size_t j = 0;
    char word[WORD_MAX_LEN];

    for (size_t i = 0; s[i] != '\0'; i++)
        if (s[i] == ' ')
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
        else
        {
            if (j + 1 == len_max)
                return 0;
            j++;
            word[j - 1] = s[i];
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

bool is_leap(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

bool is_year_correct(char year[])
{
    bool res = true;
    for (size_t i = 0; year[i] != '\0'; i++)
        if (!isdigit(year[i]))
            res = false;

    if (res)
    {
        int num = (int)strtol(year, NULL, 10);
        if (num < 0 || num > 9999)
            res = false;
    }

    return res;
}

bool is_month_correct(char month[], size_t i)
{
    return strcmp(month, months[i]) == 0;
}

bool is_day_correct(char day[], size_t month, char year[])
{
    bool res = false;
    int num;
    for (size_t i = 0; day[i] != '\0'; i++)
        if (!isdigit(day[i]))
            return false;

    num = (int)strtol(day, NULL, 10);

    if (month == 1)
    {
        int iyear = (int)strtol(year, NULL, 10);
        if (is_leap(iyear) && 0 < num && num <= 29)
            res = true;
        else if (!is_leap(iyear) && 0 < num && num <= 28)
            res = true;
        else
            return false;
    }

    if ((month < 7 && month % 2 == 0) || (month >= 7 && month % 2 != 0))
        if (0 < num && num <= 31)
            res = true;

    if ((month < 7 && month % 2 != 0) || (month > 7 && month % 2 == 0))
        if (0 < num && num <= 30)
            res = true;

    return res;
}


bool is_date(word_array_t words)
{
    bool is_year = false;
    bool is_day = false;

    char month[WORD_MAX_LEN + 1];
    size_t k;
    for (k = 0; k < strlen(words[1]); k++)
        month[k] = (char)tolower(words[1][k]);
    month[k] = '\0';

    for (size_t j = 0; j < 12; j++)
        if (is_month_correct(month, j))
        {
            is_year = is_year_correct(words[2]);
            if (is_year)
                is_day = is_day_correct(words[0], j, words[2]);
            if (is_year && is_day)
                return true;
        }
    return false;
}
