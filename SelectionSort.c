#include <stdio.h>
void main()
{
    int a[100], i, j, n, temp, select;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        select = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[select])
            {
                select = j;
            }
        }
        temp = a[select];
        a[select] = a[i];
        a[i] = temp;
    }
    printf("After sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
