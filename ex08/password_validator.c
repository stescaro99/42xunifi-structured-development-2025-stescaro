#include "password_validator.h"

int ft_strlen(const char *s)
{
    if (!s)
        return 0;
    int i=0;
    while (s[i])
        i++;
    return i;
}

static bool check_cases(const char *s)
{
    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool special = false;

    for (int i=0; s[i]; i++)
    {
        if (s[i] < 91 && s[i] > 64)
            upper = true;
        else if (s[i] < 123 && s[i] > 96)
            lower = true;
        else if (s[i] < ':' && s[i] > 47)
            digit = true;
        else if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '^' || s[i] == '&' || s[i] == '*')
            special = true;
    }
    if (!upper || !lower || !digit || !special)
        return false;
    return true;
}

static  diff_pass(const char *s, const char *t)
{
    if (ft_strlen(s) != ft_strlen(t))
        return true;
    for (int i=0; s[i] && t[i]; i++)
    {
        if (s[i] != t[i])
            return true;
    }
    return false;
}

PwStatus validate_password_weak(const char *new_pw, const char *curr_pw)
{
    if (ft_strlen(new_pw) > 7 && check_cases(new_pw) && diff_pass(new_pw, curr_pw))
        return 0;
    return 1;
}