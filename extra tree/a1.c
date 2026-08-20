#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

int findHeight(Node *root)
{
    int leftHeight;
    int rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = findHeight(root->left);
    rightHeight = findHeight(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

void findLongestPath(Node *root)
{
    Node *currentNode;
    int leftHeight;
    int rightHeight;

    if (root == NULL)
        return;

    currentNode = root;

    printf("\nLongest Path From Root: ");
    printf("%d", currentNode->data);

    while (currentNode->left != NULL || currentNode->right != NULL)
    {
        leftHeight = findHeight(currentNode->left);
        rightHeight = findHeight(currentNode->right);

        if (leftHeight >= rightHeight)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

        printf(" -> %d", currentNode->data);
    }

    printf("\nNumber of Nodes = %d", findHeight(root));
    printf("\nNumber of Levels = %d\n", findHeight(root));
}

void findBalance(Node *root)
{
    int leftHeight;
    int rightHeight;
    int balance;

    if (root == NULL)
        return;

    findBalance(root->left);

    leftHeight = findHeight(root->left);
    rightHeight = findHeight(root->right);

    balance = leftHeight - rightHeight;

    printf("Node %d : Balance Factor = %d : ", root->data, balance);

    if (balance >= 2)
        printf("Critical Node\n");
    else if (balance <= -2)
        printf("Critical Node\n");
    else if (balance == 1)
        printf("Left Heavy\n");
    else if (balance == -1)
        printf("Right Heavy\n");
    else
        printf("Balanced\n");

    findBalance(root->right);
}

void displayTree(Node *root)
{
    if (root == NULL)
        return;

    displayTree(root->left);
    printf("%d ", root->data);
    displayTree(root->right);
}

int main()
{
    Node *root = NULL;
    int numberOfNodes;
    int value;
    int levels;

    printf("Enter number of nodes: ");
    scanf("%d", &numberOfNodes);

    printf("Enter node values:\n");

    for (int i = 0; i < numberOfNodes; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nInorder Traversal: ");
    displayTree(root);

    levels = findHeight(root);

    printf("\n\nNumber of Levels = %d\n", levels);

    findLongestPath(root);

    printf("\n\nBalance Status of Each Node:\n");
    findBalance(root);

    return 0;
}