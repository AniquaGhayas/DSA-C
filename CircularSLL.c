#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node snode;
snode *head = NULL;

void CreateList(int x) {
    snode *tempnode = NULL;
    tempnode = (snode*)malloc(sizeof(snode));
    tempnode->data = x;
    tempnode->next = tempnode; // circular link to itself
    head = tempnode;
}

void appendnode(int x) {
    snode *tempnode = head;
    snode *newnode = NULL;
    newnode = (snode*)malloc(sizeof(snode));
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->next = newnode; // self-loop
        head = newnode;
        return;
    }

    while (tempnode->next != head) {
        tempnode = tempnode->next;
    }
    tempnode->next = newnode;
    newnode->next = head;
    return;
}

void PrintList(void) {
    snode *tempnode = head;

    if (head == NULL) {
        printf("List is empty...\n");
        return;
    }

    do {
        printf("%d==>", tempnode->data);
        tempnode = tempnode->next;
    } while (tempnode != head);
    printf("(back to head)\n");
    return;
}

void Insert(int x) { // Insert at beginning
    snode *newnode = NULL;
    newnode = (snode*)malloc(sizeof(snode));
    newnode->data = x;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
        return;
    }

    snode *tempnode = head;
    while (tempnode->next != head) {
        tempnode = tempnode->next;
    }

    newnode->next = head;
    tempnode->next = newnode;
    head = newnode;
    return;
}

void Delete(void) { // Delete first node
    snode *tempnode = head;

    if (head == NULL) {
        printf("List is empty...\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    snode *last = head;
    while (last->next != head) {
        last = last->next;
    }

    last->next = head->next;
    head = head->next;
    free(tempnode);
    return;
}

void InsertByPosition(int pos, int x) {
    snode *newnode = NULL;
    newnode = (snode*)malloc(sizeof(snode));
    newnode->data = x;

    if (pos == 1) {
        Insert(x);
        return;
    }

    snode *tempnode = head;
    int position = 1;

    while (position < pos - 1 && tempnode->next != head) {
        tempnode = tempnode->next;
        position++;
    }

    if (position != pos - 1) {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }

    newnode->next = tempnode->next;
    tempnode->next = newnode;
    return;
}

void DeleteLastNode() {
    if (head == NULL) {
        printf("List is empty...\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    snode *tempnode = head;

    while (tempnode->next->next != head) {
        tempnode = tempnode->next;
    }

    snode *lastnode = tempnode->next;
    tempnode->next = head;
    free(lastnode);
    return;
}

void main() {
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

    InsertByPosition(3, 35);
    PrintList();

    DeleteLastNode();
    PrintList();
}
