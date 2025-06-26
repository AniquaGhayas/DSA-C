#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node snode;

snode* createNode(int x)
{
    snode *newNode = (snode*) malloc(sizeof(snode));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    snode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Root node: %d\n", root->data);
    printf("Left child of root: %d\n", root->left->data);
    printf("Right child of root: %d\n", root->right->data);
    printf("Left child of node 2: %d\n", root->left->left->data);
    printf("Right child of node 2: %d\n", root->left->right->data);

    return 0;
}

