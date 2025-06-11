#include "segmented_runs.h"

int count_segments(const int *arr, int size)
{
    if (size < 3)
        return 0;
    int count = 0;
    for (int end_index = 0; end_index < size; end_index++)
    {
        int start_index = end_index;
        while (end_index < size && arr[end_index] != -1)
            end_index++;
        if (end_index - start_index > 2)
        {
            int n = arr[start_index];
            int conseccutive = 0;

            while (start_index++ != end_index)
            {
                ++n;
                if (n != arr[start_index])
                {
                    conseccutive = 0;
                    n = arr[start_index];
                }
                else
                    conseccutive++;
                if (conseccutive == 2)
                {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}
/*
int main() {
    int arr1[] = {1, 2, 3, -1, 5, 6, 7, 8, -1, 10, 11, 12};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = count_segments(arr1, size1);
    printf("Test 1: %d\n", result1);

    int arr2[] = {1, 2, -1, 3, 4, 5, -1, 6, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = count_segments(arr2, size2);
    printf("Test 2: %d\n", result2);

    int arr3[] = {1, -1, 2, 3, 4, -1, 1, 5, 6, 7, 11, 8};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int result3 = count_segments(arr3, size3);
    printf("Test 3: %d\n", result3);

    int arr4[] = {1, 2, -1, 3, -1, 4};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int result4 = count_segments(arr4, size4);
    printf("Test 4: %d\n", result4);

    return 0;
}*/