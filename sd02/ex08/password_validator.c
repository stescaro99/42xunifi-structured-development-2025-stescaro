#include "password_validator.h"

static int ft_strlen(const char *s)
{
    if (!s)
        return 0;
    int i=0;
    while (s[i])
        i++;
    return i;
}

static short check_cases(const char *s)
{
    short upper = 0;
    short lower = 0;
    short digit = 0;
    short special = 0;

    for (int i=0; s[i]; i++)
    {
        if (s[i] < 91 && s[i] > 64)
            upper = 1;
        else if (s[i] < 123 && s[i] > 96)
            lower = 1;
        else if (s[i] < ':' && s[i] > 47)
            digit = 1;
        else if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '^' || s[i] == '&' || s[i] == '*')
            special = 1;
    }
    if (!upper || !lower || !digit || !special)
        return 0;
    return 1;
}

static short diff_pass(const char *s, const char *t)
{
    if (ft_strlen(s) != ft_strlen(t))
        return 1;
    int i = 0;
    while (i > -1 && s[i] && t[i])
    {
        if (s[i] != t[i])
            i = -10;
        i++;
    }
    if (i < 0)
        return 1;
    return 0;
}

PwStatus validate_password_weak(const char *new_pw, const char *curr_pw)
{
    if (ft_strlen(new_pw) > 7 && check_cases(new_pw) && diff_pass(new_pw, curr_pw))
        return 0;
    return 1;
}