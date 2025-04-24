#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node snode;
snode *front = NULL, *rear = NULL;

void enqueue(int x)
{
    snode *newNode = (snode*)malloc(sizeof(snode));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d is enqueued into the queue\n", x);
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int x = front->data;
    snode *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return x;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // no error: dynamic allocation

    printf("%d dequeued\n", dequeue());
    printf("%d dequeued\n", dequeue());
    printf("%d dequeued\n", dequeue());
    printf("%d dequeued\n", dequeue());
    printf("%d dequeued\n", dequeue());
    printf("%d dequeued\n", dequeue());
    printf("%d dequeued\n", dequeue()); // error: queue is empty

    return 0;
}
