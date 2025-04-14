#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node snode;
snode *top = NULL;

void push(int data)
{
    snode *newNode = (snode*)malloc(sizeof(snode));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", data);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    snode *temp = top;
    int poppedData = top->data;
    top = top->next;
    free(temp);
    printf("%d popped from stack\n", poppedData);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    snode *temp = top;
    printf("Stack Elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, data;
    printf("Enter the number of elements to push into the stack: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        push(data);
    }
    display();
    printf("\nPerforming pop operation...\n");
    pop();
    display();
    return 0;
}
