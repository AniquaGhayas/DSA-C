#include<stdio.h>
void main()
{
    int a[100], i, n, key, left, right, mid;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d elements (sorted in ascending order):\n", n);
    for(i = 0; i < n; i++)
    {
    scanf("%d", &a[i]);
    }
    printf("Enter key element to search:\n");
    scanf("%d", &key);
    left = 0;
    right = n - 1;
    int found = 0;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(a[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if(a[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if(!found)
    {
        printf("Element NOT found\n");
    }
}

