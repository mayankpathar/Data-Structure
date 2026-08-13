// 78. Given a binary tree, determine if it is height-balanced
// (A height-balanced binary tree is a binary tree in which the depth of the
// two subtrees of every node never differs by more than one).

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->info = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int heightBalanced(struct Node *root, int *isBalanced)
{
    if (root == NULL)
        return 0;

    int leftHeight = heightBalanced(root->left, isBalanced);
    int rightHeight = heightBalanced(root->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1)
        *isBalanced = 0;

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main()
{
    struct Node *root1 = newNode(3);
    root1->left = newNode(9);
    root1->right = newNode(20);
    root1->right->left = newNode(15);
    root1->right->right = newNode(7);

    int balanced1 = 1;
    heightBalanced(root1, &balanced1);
    printf("Sample 1: %s\n", balanced1 ? "TRUE" : "FALSE");

    struct Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->left = newNode(3);
    root2->left->right = newNode(3);
    root2->left->left->left = newNode(4);
    root2->left->left->right = newNode(4);

    int balanced2 = 1;
    heightBalanced(root2, &balanced2);
    printf("Sample 2: %s\n", balanced2 ? "TRUE" : "FALSE");

    return 0;
}