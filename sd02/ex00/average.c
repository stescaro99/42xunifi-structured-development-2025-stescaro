#include "average.h"

static int is_valid_score(int value)
{
    return (value >= 0 && value <= 100);
}

float average(const int *array, int size)
{
    int sum = 0;
    int count = 0;
    int i;

    if (array == 0 || size <= 0)
        return 0.0f;
    for (i = 0; i < size; i++)
    {
        if (is_valid_score(array[i]))
        {
            sum += array[i];
            count++;
        }
    }
    if (count == 0)
        return 0.0f;
    return (float)sum / count;
}