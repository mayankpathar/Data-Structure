// Write a menu driven program to implement Binary Search Tree (BST) & perform following operations:
//  Insert a node
//  Delete a node
//  Search a node
//  Preorder Traversal
//  Postorder Traversal
//  Inorder Traversal
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void insert(struct node **root, int data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL) 
    {
        *root = newNode;
        return;
    }

    struct node *current = *root;
    struct node *parent = NULL;

    while (current != NULL) 
    {
        parent = current;
        if (data < current->data) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }

    if (data < parent->data) 
    {
        parent->left = newNode;
    } 
    else 
    {
        parent->right = newNode;
    }
    
}
void delete(struct node **root, int data) 
{
    if (*root == NULL) 
    {
        printf("Node not found.\n");
        return;
    }

    if (data < (*root)->data) 
    {
        delete(&((*root)->left), data);
    } 
    else if (data > (*root)->data) 
    {
        delete(&((*root)->right), data);
    } 
    else 
    {
        if ((*root)->left == NULL && (*root)->right == NULL) 
        {
            free(*root);
            *root = NULL;
        } 
        else if ((*root)->left == NULL) 
        {
            struct node *temp = *root;
            *root = (*root)->right;
            free(temp);
        } 
        else if ((*root)->right == NULL) 
        {
            struct node *temp = *root;
            *root = (*root)->left;
            free(temp);
        } 
        else 
        {
            struct node *temp = findMin((*root)->right);
            (*root)->data = temp->data;
            delete(&((*root)->right), temp->data);
        }
    }
}