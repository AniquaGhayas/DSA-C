#include<stdio.h>
void main()
{
    int a[100], i, n, key;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i=1;i<=n; i++)
        scanf("%d", &a[i]);
    printf("Enter key element to search:\n");
    scanf("%d", &key);
    for(i=1;i<=n;i++)
        if(a[i]==key)
    {
        printf("Element found");
        break;
    }
    if(i==n+1)
        printf("Element NOT found");

}
