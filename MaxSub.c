#include <stdio.h>
int kadane(int a[], int size)
{
    int i, cursum = 0, maxsum = 0;
    for (i = 0; i < size; i++)
    {
        cursum += a[i];
        if (cursum > 0)
        {
            maxsum = cursum;
        }
        else
        {
            cursum = 0;
        }
    }
    return maxsum;
}
int main()
{
    int a[] = {5, -4, 2, 6, 1};
    int size = sizeof(a) / 4;
    int result = kadane(a, size);
    printf("%d", result);
}