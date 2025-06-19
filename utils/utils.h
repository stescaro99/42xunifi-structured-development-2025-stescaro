#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

int ft_strlen(const char *s);
int strcasestr_custom(const char *haystack, const char *needle);
bool diff_pass(const char *s, const char *t);
bool check_cases(const char *s);
const char* plusminus_mapper(int score);
const char* passfail_mapper(int score);
const char* standard_mapper(int score);

#endif