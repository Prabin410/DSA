#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
    struct Node *parent;
} Node;
Node *createNode(int data, Node *parent)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    newNode->parent = parent;
    return newNode;
}
void updateHeight(Node *node)
{

    int hl = 0, hr = 0;
    if (node->left)
    {
        hl = node->left->height;
    }
    else
    {
        hl = 0;
    }
    if (node->right)
    {
        hr = node->right->height;
    }
    else
    {
        hr = 0;
    }
    if (hl > hr)
    {
        node->height = hl + 1;
    }
    else
    {
        node->height = hr + 1;
    }
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}
Node *leftRightRotate(Node *z)
{
    z->left = rightRotate(z->left);
    return rightRotate(z);
}
Node *rightLeftRotate(Node *z)
{
    z->right = leftRotate(z->right);
    return leftRotate(z);
    printf("Right Left Rotate\n");
}
int main()
{

    struct Node *root = NULL;

    root = createNode(10, NULL);
    root->left = createNode(5, root);
    root->right = createNode(20, root);
    root->right->left = createNode(18, root->right);
    root->right->right = createNode(23, root->right);

    printf("Root: %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);
    return 0;
}
