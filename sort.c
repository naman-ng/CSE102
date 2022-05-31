#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int compareInt(const void *pa, const void *pb)
{
    const int *p1 = pa;
    const int *p2 = pb;
    return *p1 - *p2;
}

int main()
{
    int t, i;
    scanf("%d", &t);
    int arr[t];
    for (i = 0; i < t; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, t, sizeof(int), compareInt);
    for (i = 0; i < t; i++)
    {
        printf("%d ", arr[i]);
    }
}