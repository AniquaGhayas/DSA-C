#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct Node* findMin(struct Node *root)
{
    if(root == NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct Node* findMax(struct Node *root)
{
     if(root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

int main() {
       struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of elements to insert in BST: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Traversals
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Min and Max
    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);
    if (minNode) printf("Minimum value: %d\n", minNode->data);
    if (maxNode) printf("Maximum value: %d\n", maxNode->data);

    // Search
    printf("Enter a value to search in BST: ");
    scanf("%d", &key);

    struct Node* found = search(root, key);
    if (found)
        printf("Value %d found in BST.\n", key);
    else
        printf("Value %d not found in BST.\n", key);

    return 0;
}
