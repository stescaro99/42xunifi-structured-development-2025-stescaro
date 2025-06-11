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

bool check_similar(const char *s, const char *t)
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