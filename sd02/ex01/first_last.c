#include "first_last.h"

static int is_valid_input(const int *arr, int size, int *first, int *last)
{
    return (arr != 0 && size > 0 && first != 0 && last != 0);
}

void first_last(const int arr[], int size, int target, int *first, int *last)
{
    int i;
    int found = 0;

    if (!is_valid_input(arr, size, first, last))
        return;

    *first = -1;
    *last = -1;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            if (!found)
            {
                *first = i;
                found = 1;
            }
            *last = i;
        }
    }
}