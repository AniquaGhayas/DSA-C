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
    dnode *tempnode = NULL;
    tempnode = (dnode*)malloc(sizeof(dnode));
    tempnode->data = x;
    tempnode->prev = tempnode->next = NULL;
    head = tail = tempnode;
    return;
}

void appendDNode(int x)
{
    dnode *tempnode = NULL, *tNode = head;
    tempnode = (dnode*)malloc(sizeof(dnode));
    tempnode->data = x;
    tempnode->prev = tempnode->next = NULL;

    if (head == NULL)
    {
        head = tail = tempnode;
        return;
    }

    while (tNode->next != NULL)
    {
        tNode = tNode->next;
    }

    tNode->next = tempnode;
    tempnode->prev = tNode;
    tail = tempnode;
    return;
}

void InsertAtBeginning(int x)
{
    dnode *tempnode = NULL;
    tempnode = (dnode*)malloc(sizeof(dnode));
    tempnode->data = x;
    tempnode->prev = NULL;
    tempnode->next = head;

    if (head == NULL)
    {
        head = tail = tempnode;
    }
    else
    {
        head->prev = tempnode;
        head = tempnode;
    }
    return;
}

void DeleteFirstNode()
{
    dnode *tempnode = NULL;
    if (head == NULL)
    {
        printf("List is empty...\n");
        return;
    }

    tempnode = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    tempnode->next = NULL;
    free(tempnode);
    return;
}

void InsertByPosition(int pos, int x)
{
    dnode *tempnode = NULL, *tNode = head;
    int position = 1;

    tempnode = (dnode*)malloc(sizeof(dnode));
    tempnode->data = x;
    tempnode->prev = tempnode->next = NULL;

    if (pos == 1)
    {
        tempnode->next = head;
        if (head != NULL)
            head->prev = tempnode;
        else
            tail = tempnode;
        head = tempnode;
        return;
    }
    while (tNode != NULL && position < pos - 1)
    {
        tNode = tNode->next;
        position++;
    }
    if (tNode == NULL)
    {
        printf("Position out of bounds\n");
        free(tempnode);
        return;
    }
    tempnode->next = tNode->next;
    tempnode->prev = tNode;

    if (tNode->next != NULL)
        tNode->next->prev = tempnode;
    else
        tail = tempnode;

    tNode->next = tempnode;
    return;
}

void DeleteLastNode()
{
    dnode *tempnode = NULL;
    if (tail == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    tempnode = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    tempnode->prev = NULL;
    free(tempnode);
    return;
}

void PrintDListForward()
{
    dnode *tNode = head;
    if (tNode == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    while (tNode != NULL)
    {
        printf("%d==>", tNode->data);
        tNode = tNode->next;
    }
    printf("\n");
    return;
}

void PrintDListBackward()
{
    dnode *tNode = tail;
    if (tNode == NULL)
    {
        printf("List is empty...\n");
        return;
    }

    while (tNode != NULL)
    {
        printf("%d==>", tNode->data);
        tNode = tNode->prev;
    }
    printf("\n");
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
