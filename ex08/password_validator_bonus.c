#include "password_validator.h"

static bool check_replace(const char *s, const char *t) {
    bool change = false;
    for (int i = 0; s[i]; i++) {
        if (s[i] != t[i]) {
            if (change)
                return false;
            change = true;
        }
    }
    return true;
}

static bool check_insert(const char *longer, const char *shorter) {
    bool change = false;
    int j = 0;
    for (int i = 0; longer[i]; i++) {
        if (!change && longer[i] != shorter[j]) {
            change = true;
            continue;
        }
        if (change && longer[i] != shorter[j])
            return false;
        j++;
    }
    return true;
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

PwStatus validate_password(const char *new_pw, PasswordHistory *history)
{
    if (validate_password_weak(new_pw, (*history)[0]) == 1)
        return 1;
    for (int i = 0; i < 3; i++)
    {
        if (check_similar(new_pw, (*history)[i]))
            return 2;
    }
    strncpy((*history)[2], (*history)[1], 1023);
    (*history)[2][1023] = '\0';
    strncpy((*history)[1], (*history)[0], 1023);
    (*history)[1][1023] = '\0';
    strncpy((*history)[0], new_pw, 1023);
    (*history)[0][1023] = '\0';
    return 0;
}