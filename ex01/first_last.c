#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
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
/*
int main()
{
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    int first = -1, last = -1;

    first_last(arr, size, target, &first, &last);

    if (first != -1 && last != -1) {
        printf("First occurrence of %d is at index %d\n", target, first);
        printf("Last occurrence of %d is at index %d\n", target, last);
    } else {
        printf("%d not found in the array.\n", target);
    }

    return 0;
}*/