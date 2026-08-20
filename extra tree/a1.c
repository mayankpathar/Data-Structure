#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int level;
};

typedef struct Node Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->level = 0;

    return newNode;
}

 Node *insertNode(Node *root, int data){
    
    if (root == NULL)
    {
        Node *newNode = createNode(data);
        newNode->level = 1; 
        return newNode;
    }
    else if (data < root->data)
    {
        Node *leftChild = insertNode(root->left, data);
        root->left = leftChild;
        leftChild->level = root->level + 1; 
    }
    else if (data > root->data)
    {
        Node *rightChild = insertNode(root->right, data);
        root->right = rightChild;
        rightChild->level = root->level + 1; 
    }
    return root;

}
void searchNode(struct Node *root, int value){
    if (root == NULL){
        printf("Value not found in the BST.\n");
        return;
    }

    if (value < root->data){
        searchNode(root->left, value);
    }
    else if (value > root->data){
        searchNode(root->right, value);
    }
    else{
            
        printf("%d",root->data);
        printf(" value node of  level ");
        printf("%d",root->level);
    }

}


int main()
{
    Node *root = NULL;
    int numberOfNodes;
    int value;
  

    printf("Enter number of nodes: ");
    scanf("%d", &numberOfNodes);

    printf("Enter node values:\n");

    for (int i = 0; i < numberOfNodes; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Enter a value to search: ");
    scanf("%d", &value);
    searchNode(root, value);

    return 0;
}