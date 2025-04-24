#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

typedef struct node dnode;
dnode *head = NULL, *tail = NULL;

void CreateDList(int x)
{
    dnode *tempnode = (dnode*)malloc(sizeof(dnode));
    tempnode->data = x;
    tempnode->prev = tempnode->next = tempnode;
    head = tail = tempnode;
    return;
}

void appendDNode(int x)
{
    dnode *tempnode = (dnode*)malloc(sizeof(dnode));
    tempnode->data = x;
    tempnode->prev = tempnode->next = NULL;

    if (head == NULL)
    {
        tempnode->next = tempnode->prev = tempnode;
        head = tail = tempnode;
        return;
    }
    tempnode->next = head;
    tempnode->prev = tail;
    tail->next = tempnode;
    head->prev = tempnode;
    tail = tempnode;
    return;
}

void InsertAtBeginning(int x)
{
    dnode *tempnode = (dnode*)malloc(sizeof(dnode));
    tempnode->data = x;
    tempnode->prev = tempnode->next = NULL;

    if (head == NULL)
    {
        tempnode->next = tempnode->prev = tempnode;
        head = tail = tempnode;
        return;
    }
    tempnode->next = head;
    tempnode->prev = tail;
    tail->next = tempnode;
    head->prev = tempnode;
    head = tempnode;
    return;
}

void DeleteFirstNode()
{
    if (head == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    dnode *tempnode = head;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        tail->next = head;
        head->prev = tail;
    }

    free(tempnode);
    return;
}

void InsertByPosition(int pos, int x)
{
    dnode *tempnode = (dnode*)malloc(sizeof(dnode));
    tempnode->data = x;
    tempnode->prev = tempnode->next = NULL;

    if (pos == 1)
    {
        InsertAtBeginning(x);
        free(tempnode);
        return;
    }
    dnode *tNode = head;
    int position = 1;

    while (position < pos - 1 && tNode->next != head)
    {
        tNode = tNode->next;
        position++;
    }
    if (position != pos - 1)
    {
        printf("Position out of bounds\n");
        free(tempnode);
        return;
    }
    tempnode->next = tNode->next;
    tempnode->prev = tNode;
    tNode->next->prev = tempnode;
    tNode->next = tempnode;

    if (tNode == tail)
    {
        tail = tempnode;
    }
    return;
}

void DeleteLastNode()
{
    if (tail == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    dnode *tempnode = tail;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }

    free(tempnode);
    return;
}

void PrintDListForward()
{
    if (head == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    dnode *tNode = head;
    do
    {
        printf("%d==>", tNode->data);
        tNode = tNode->next;
    }
    while (tNode != head);
    printf("(head)\n");
    return;
}

void PrintDListBackward()
{
    if (tail == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    dnode *tNode = tail;
    do
    {
        printf("%d==>", tNode->data);
        tNode = tNode->prev;
    }
    while (tNode != tail);
    printf("(tail)\n");
    return;
}

void main()
{
    CreateDList(5);
    PrintDListForward();
    appendDNode(10);
    PrintDListForward();
    appendDNode(15);
    PrintDListForward();
    appendDNode(20);
    PrintDListForward();
    InsertAtBeginning(25);
    PrintDListForward();
    InsertAtBeginning(30);
    PrintDListForward();
    DeleteFirstNode();
    PrintDListForward();
    InsertByPosition(3, 35);
    PrintDListForward();
    DeleteLastNode();
    PrintDListForward();
    PrintDListBackward();
}
