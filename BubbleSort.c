#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    int i, a, b, c, j, n;
    bool flag = false;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (flag == false)
    {
        flag = true;
        for (i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                flag = false;
                c = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = c;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}