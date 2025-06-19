#include "critical_windows.h"

static int condition1(const int *arr)
{
    int i, count = 0;
    for (i = 0; i < 5; i++)
    {
        if (arr[i] >= 70)
            count++;
    }
    return (count > 2);
}

static int condition2(const int *arr)
{
    int i;
    int found = 0;
    for (i = 0; i < 5; i++)
    {
        if (arr[i] > 150)
            found = 1;
    }
    if (found)
        return 0;
    return 1;
}

static int condition3(const int *arr)
{
    int sum = 0, i;
    for (i = 0; i < 5; i++)
        sum += arr[i];
    return ((sum / 5) >= 90);
}

int count_critical_windows(const int *readings, int size)
{
    int count = 0;
    int i;

    if (readings == 0 || size < 5)
        return 0;
    for (i = 0; i <= size - 5; i++)
    {
        if (condition1(&readings[i]) || condition2(&readings[i]) || condition3(&readings[i]))
            count++;
    }
    return count;
}