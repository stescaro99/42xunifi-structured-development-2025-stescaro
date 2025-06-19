#include "password_validator.h"

PwStatus validate_password_weak(const char *new_pw, const char *curr_pw)
{
    if (ft_strlen(new_pw) > 7 && check_cases(new_pw) && diff_pass(new_pw, curr_pw))
        return 0;
    return 1;
}