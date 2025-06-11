#include <stdbool.h>

static bool condition1(const int *arr)
{
    int count=0;
    for (int i=0; i < 5; i++)
    {
        if (arr[i] >= 70)
            count++;
    }
    if (count > 2)
        return true;
    return false;
}

static bool condition2(const int *arr)
{
    for (int i=0; i < 5; i++)
    {
        if (arr[i] > 150)
            return false;
    }
    return true;
}

static bool condition3(const int *arr)
{
    if ((arr[0] + arr[1] + arr[2] + arr[3] + arr[4])/5 >= 90)
        return true;
    return false;
}

int count_critical_windows(const int *readings, int size)
{
    if (size < 5)
        return 0;
    int count=0;
    for (int i=0; i < size - 4; i++)
    {
        if (condition1(&readings[i]) || condition2(&readings[i]) || condition3(&readings[i]))
            count++;
    }
    return count;
}
/*
int main()
{
    int readings1[] = {65, 72, 80, 90, 60, 100, 110, 120};
    int size1 = sizeof(readings1) / sizeof(readings1[0]);
    printf("Critical windows (test 1): %d\n", count_critical_windows(readings1, size1));

    int readings2[] = {50, 55, 60, 65, 70};
    int size2 = sizeof(readings2) / sizeof(readings2[0]);
    printf("Critical windows (test 2): %d\n", count_critical_windows(readings2, size2));

    int readings3[] = {151, 20, 30, 40, 50, 60, 70};
    int size3 = sizeof(readings3) / sizeof(readings3[0]);
    printf("Critical windows (test 3): %d\n", count_critical_windows(readings3, size3));

    int readings4[] = {100, 100, 100, 100, 100};
    int size4 = sizeof(readings4) / sizeof(readings4[0]);
    printf("Critical windows (test 4): %d\n", count_critical_windows(readings4, size4));

    int readings5[] = {10, 20, 30};
    int size5 = sizeof(readings5) / sizeof(readings5[0]);
    printf("Critical windows (test 5): %d\n", count_critical_windows(readings5, size5));

    return 0;
}
*/
