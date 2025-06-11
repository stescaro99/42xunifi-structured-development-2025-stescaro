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
/*
int main() {
    int values1[] = {90, 80, 70, 60, 50};
    int values2[] = {100, -5, 105, 80};
    int values3[] = {};
    int values4[] = {101, -1, 200};

    printf("Average 1: %.2f\n", average(values1, 5));
    printf("Average 2: %.2f\n", average(values2, 4));
    printf("Average 3: %.2f\n", average(values3, 0));
    printf("Average 4: %.2f\n", average(values4, 3));

    return 0;
}*/