#ifndef PASSWORD_VALIDATOR_BONUS_H
#define PASSWORD_VALIDATOR_BONUS_H

#include <stdbool.h>
#include <string.h>

typedef short PwStatus;
typedef char PasswordHistory[3][1024];

PwStatus validate_password_weak(const char *new_pw, const char *curr_pw);
PwStatus validate_password(const char *new_pw, PasswordHistory *history);
int ft_strlen(const char *s);

#endif