#include "first_last.h"

void first_last(const int arr[], int size, int target, int *first, int *last)
{
    short found = 0;
    for (int i = 0; i < size; i++)
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