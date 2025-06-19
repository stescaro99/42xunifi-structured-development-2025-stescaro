#include "segmented_runs.h"

static int has_consecutive_run(const int *arr, int start, int end)
{
    int i;
    int consecutive = 0;
    int found = 0;

    if (end - start < 3)
        return 0;
    for (i = start + 1; i < end; ++i)
    {
        if (arr[i] == arr[i - 1] + 1)
            consecutive++;
        else
            consecutive = 0;
        if (consecutive == 2)
            found = 1;
    }
    return found;
}

int count_segments(const int *arr, int size)
{
    int count = 0;
    int i = 0;
    int start;

    if (arr == 0 || size < 3)
        return 0;
    while (i < size)
    {
        while (i < size && arr[i] == -1)
            i++;
        start = i;
        while (i < size && arr[i] != -1)
            i++;
        if (has_consecutive_run(arr, start, i))
            count++;
    }
    return count;
}