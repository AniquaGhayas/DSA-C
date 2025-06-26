#include<stdio.h>
#define size 5

int cqueue[size];
int front = -1, rear = -1;

void enque(int ele)
{
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front)
    {
        printf("Circular Queue is full...\n");
        return;
    }

    if (front == -1) // First insertion
        front = rear = 0;
    else
        rear = (rear + 1) % size;

    cqueue[rear] = ele;
    printf("%d is enqueued into the circular queue\n", ele);
}

int deque()
{
    if (front == -1)
    {
        printf("Circular Queue is empty\n");
        return -1;
    }

    int ele = cqueue[front];

    if (front == rear) // Only one element
        front = rear = -1;
    else
        front = (front + 1) % size;

    return ele;
}

void PrintQueue()
{
    if (front == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", cqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

void main()
{
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    enque(50); // Should show full after this
    enque(60);

    PrintQueue();

    printf("%d is dequeued\n", deque());
    printf("%d is dequeued\n", deque());

    PrintQueue();

    enque(60);
    enque(70); // This should fill the queue again
    PrintQueue();

    enque(80); // Should show full
}
