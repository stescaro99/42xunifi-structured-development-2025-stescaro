static short condition1(const int *arr)
{
    int count=0;
    for (int i=0; i < 5; i++)
    {
        if (arr[i] >= 70)
            count++;
    }
    if (count > 2)
        return 1;
    return 0;
}

static short condition2(const int *arr)
{
    int i = 0;
    while (i < 5)
    {
        if (arr[i] > 150)
            i = 5;
        i++;
    }
    return (i == 5);
}

static short condition3(const int *arr)
{
    if ((arr[0] + arr[1] + arr[2] + arr[3] + arr[4])/5 >= 90)
        return 1;
    return 0;
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