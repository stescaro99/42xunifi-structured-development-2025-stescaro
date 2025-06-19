#include "utils.h"

bool check_cases(const char *s)
{
    bool upper = false, lower = false, digit = false, special = false;
    for (int i = 0; s[i]; i++)
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

bool diff_pass(const char *s, const char *t)
{
    int different = 0;
    if (ft_strlen(s) != ft_strlen(t))
        return true;
    for (int i = 0; s[i] && t[i]; i++)
    {
        if (s[i] != t[i])
            different = 1;
    }
    return (different != 0);
}
