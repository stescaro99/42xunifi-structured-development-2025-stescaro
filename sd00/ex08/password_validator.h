#include <stdbool.h>
#include <string.h>
#include "../../utils/utils.h"

typedef short PwStatus;
typedef char PasswordHistory[3][1024];

PwStatus validate_password_weak(const char *new_pw, const char *curr_pw);
PwStatus validate_password(const char *new_pw, PasswordHistory *history);
