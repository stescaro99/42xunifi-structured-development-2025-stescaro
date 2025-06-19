#include "password_validator.h"

static bool check_replace(const char *s, const char *t)
{
    bool change = false;
    int i = 0;
    int fail = 0;
    while (s[i] && t[i])
    {
        if (s[i] != t[i])
        {
            if (change)
                fail = 1;
            change = true;
        }
        i++;
    }
    return (fail == 0);
}

static bool check_insert(const char *longer, const char *shorter)
{
    bool change = false;
    int i = 0, j = 0;
    int fail = 0;
    while (longer[i])
    {
        if (!change && longer[i] != shorter[j])
        {
            change = true;
            i++;
        }
        else if (change && longer[i] != shorter[j])
            fail = 1;
        else
        {
            i++;
            j++;
        }
    }
    return (fail == 0);
}

static bool check_similar(const char *s, const char *t)
{
    int len_s = ft_strlen(s);
    int len_t = ft_strlen(t);

    if (len_s == len_t)
        return check_replace(s, t);
    if (len_s == len_t + 1)
        return check_insert(s, t);
    if (len_s + 1 == len_t)
        return check_insert(t, s);
    return false;
}

static void safe_strcpy(char *dest, const char *src, size_t dest_size)
{
    size_t i = 0;
    if (dest_size == 0)
        return;
    while (i < dest_size - 1 && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

PwStatus validate_password(const char *new_pw, PasswordHistory *history)
{
    bool valid_password = true;

    if (validate_password_weak(new_pw, (*history)[0]) == 1)
        return 1;
    for (int i = 0; valid_password && i < 3; i++)
    {
        if (check_similar(new_pw, (*history)[i]))
            valid_password = false;
    }
    if (!valid_password)
        return 2;
    safe_strcpy((*history)[2], (*history)[1], 1024);
    safe_strcpy((*history)[1], (*history)[0], 1024);
    safe_strcpy((*history)[0], new_pw, 1024);
    return 0;
}
