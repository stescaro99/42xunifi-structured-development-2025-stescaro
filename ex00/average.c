#include "average.h"

float average(const int *array, int size) 
{
    if (size <= 0 || array == NULL) 
        return 0.0f;
    int total = 0;
    int number = 0;
    
    for (int i = 0; i < size; i++) 
    {
        if (array[i] < 0 || array[i] > 100)
            continue;
        total += array[i];
        number++;
    }
    if (total == 0) 
        return 0.0f;
    return (float)total / number;
}