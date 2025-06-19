#include "password_validator.h"

static int ft_strlen(const char *s)
{
    int i = 0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

static bool check_cases(const char *s)
{
    bool upper = false, lower = false, digit = false, special = false;
    int i;
    for (i = 0; s[i]; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            upper = true;
        else if (s[i] >= 'a' && s[i] <= 'z')
            lower = true;
        else if (s[i] >= '0' && s[i] <= '9')
            digit = true;
        else if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '^' || s[i] == '&' || s[i] == '*')
            special = true;
    }
    return (upper && lower && digit && special);
}

static bool diff_pass(const char *s, const char *t)
{
    int i;
    int different = 0;
    if (ft_strlen(s) != ft_strlen(t))
        return true;
    for (i = 0; s[i] && t[i]; i++)
    {
        if (s[i] != t[i])
            different = 1;
    }
    return (different != 0);
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
    if (ft_strlen(new_pw) > 7 && check_cases(new_pw) && diff_pass(new_pw, curr_pw))
        return 0;
    return 1;
}