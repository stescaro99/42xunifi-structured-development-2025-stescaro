#include "first_last.h"

void first_last(const int arr[], int size, int target, int *first, int *last)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            if (!found)
            {
                *first = i;
                found = true;
            }
            *last = i;
        }
    }
}