#include "password_validator.h"

static short check_replace(const char *s, const char *t)
{
    short change = 0;
    int i = 0;
    while (i > -1 && s[i])
    {
        if (s[i] != t[i])
        {
            if (change)
                i = -10;
            change = 1;
        }
        i++;
    }
    if (i < 0)
        return 0;
    return 1;
}

static short check_insert(const char *longer, const char *shorter)
{
    short change = 0;
    int j = 0;
    for (int i = 0; j > -1 && longer[i]; i++)
    {
        if (change || longer[i] == shorter[j])
        {
            if (longer[i] != shorter[j])
                j = -10;
            j++;
        }
        else
            change = 1;
    }
    if (j < 0)
        return 0;
    return 1;
}

static short check_similar(const char *s, const char *t)
{
    int len_s = ft_strlen(s);
    int len_t = ft_strlen(t);

    if (len_s == len_t)
        return check_replace(s, t);
    if (len_s == len_t + 1)
        return check_insert(s, t);
    if (len_s + 1 == len_t)
        return check_insert(t, s);
    return 0;
}

static void safe_strcpy(char *dest, const char *src, size_t dest_size)
{
    if (dest_size == 0)
        return;
    size_t i = 0;
    while (i < dest_size - 1 && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

PwStatus validate_password(const char *new_pw, PasswordHistory *history)
{
    if (validate_password_weak(new_pw, (*history)[0]) == 1)
        return 1;
    int i = 0;
    while (i < 3)
    {
        if (check_similar(new_pw, (*history)[i]))
            i = 30;
        i++;
    }
    if (i > 3)
        return 2;
    safe_strcpy((*history)[2], (*history)[1], 1024);
    safe_strcpy((*history)[1], (*history)[0], 1024);
    safe_strcpy((*history)[0], new_pw, 1024);
    return 0;
}