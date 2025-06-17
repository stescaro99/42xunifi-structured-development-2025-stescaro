#include "segmented_runs.h"

static int has_consecutive_run(const int *arr, int start, int end)
{
    if (end - start < 3)
        return 0;
    int n = arr[start];
    int consecutive = 0;
    for (int i = start + 1; i < end; ++i)
    {
        if (arr[i] == n + 1)
        {
            consecutive++;
            n = arr[i];
            if (consecutive == 2)
            {
                consecutive++;
                i = end - 1;
            }
        }
        else
        {
            consecutive = 0;
            n = arr[i];
        }
    }
    if (consecutive > 2)
        return 1;
    return 0;
}

int count_segments(const int *arr, int size)
{
    if (size < 3)
        return 0;
    int count = 0;
    int i = 0;
    while (i < size)
    {
        if (arr[i] != -1)
        {
            int start = i;
            while (i < size && arr[i] != -1)
                ++i;
            if (has_consecutive_run(arr, start, i))
                ++count;
        }
        else
            i++;
    }
    return count;
}