#include <stdio.h>

void main() {
    int a[100], n, i, j, key;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
         // Move elements of a[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    printf("After sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
