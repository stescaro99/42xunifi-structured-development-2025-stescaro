#include <stddef.h>
#include <ctype.h>
#include "utils.h"

int strcasestr_custom(const char *haystack, const char *needle)
{
    int nlen = ft_strlen(needle);
    int hlen = ft_strlen(haystack);
    int j;

    if (nlen == 0)
        return 1;
    for (int i = 0; i <= hlen - nlen; i++)
    {
        j = 0;
        while (j < nlen &&
               tolower((unsigned char)haystack[i + j]) == tolower((unsigned char)needle[j]))
            j++;
        if (j == nlen)
            return 1;
    }
    return 0;
}
