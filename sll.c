#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node snode;
snode *head=NULL;

void CreateList(int x)
{
    snode *tempnode=NULL;
    tempnode=(snode*)malloc(sizeof(snode));
    tempnode->data=x;
    tempnode->next=NULL;
    head=tempnode;
}
void appendnode(int x) // insertion at the end
{
    snode *tempnode=head;
    snode *newnode=NULL;
    newnode=(snode*)malloc(sizeof(snode));
    newnode->data=x;
    newnode->next=NULL;
    if(tempnode==NULL)
    {
        head=newnode;
        return;
    }
    while(tempnode->next!=NULL)
    {
        tempnode=tempnode->next;
    }
    tempnode->next=newnode;
    return;
}
void PrintList(void)
{
    snode *tempnode=head;
    if(tempnode=NULL)
    {
        printf("list is empty...\n");
        return;
    }
    for(tempnode=head;tempnode!=NULL;tempnode=tempnode->next)
        printf("%d==>", tempnode->data);
        printf("\n");
    return;
}
void Insert(int x) //insertion at the end
{
    snode *newnode = NULL;
    newnode=(snode*)malloc(sizeof(snode));
    newnode->data=x;
    newnode->next=head;
    head=newnode;
}
void Delete(void)
{
    snode *tempnode=NULL;
    tempnode=head;
    head=head->next;
    tempnode->next=NULL;
    free(tempnode);
}
void InsertByPosition(int pos, int x) {
    snode *newnode = NULL;
    newnode = (snode*)malloc(sizeof(snode));
    newnode->data = x;
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    snode *tempnode = head;
    int position = 1;
    while (tempnode != NULL && position < pos - 1)
    {
        tempnode = tempnode->next;
        position++;
    }
    if (tempnode == NULL)
    {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }
    newnode->next = tempnode->next;
    tempnode->next = newnode;
}
void DeleteLastNode()
{
    snode *tempnode = head;
    while (tempnode->next->next != NULL)
    {
        tempnode = tempnode->next;
    }
    snode *lastnode = tempnode->next;
    tempnode->next = NULL;
    free(lastnode);
}


void main()
{
    CreateList(5);
    PrintList();
    appendnode(10);
    PrintList();
    appendnode(15);
    PrintList();
    appendnode(20);
    PrintList();
    Insert(25);
    PrintList();
    Insert(30);
    PrintList();
    Delete();
    PrintList();
    InsertByPosition(3,35);
    PrintList();
    DeleteLastNode();
    PrintList();

}
