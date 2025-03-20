#include<stdio.h>
#define size 5
int dpointer, epointer, ar[size];
void enque(int ele)
{
    if (epointer<size-1)
        {
            epointer++;
            ar[epointer]=ele;
            printf("%d is enqueued into the queue\n", ele);
        }
        else
        {
            printf("Queue if full...\n");
        }
}
int deque(void)
{
    if (dpointer!=epointer)
    {
        dpointer++;
        return ar[dpointer];
    }
    else
    {
        printf("Queue is empty\n");
        return -1;
    }
}
int main()
{
    dpointer=epointer=-1;

    enque(10);
    enque(20);
    enque(30);
    enque(40);
    enque(50);
    enque(60); //error:queue is full

    printf("%d\n", deque());
    printf("%d\n", deque());
    printf("%d\n", deque());
    printf("%d\n", deque());
    printf("%d\n", deque());
    printf("%d\n", deque()); //error:queue is empty

    return 0;
}



