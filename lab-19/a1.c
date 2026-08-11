// Write a menu driven program to implement Binary Search Tree (BST) & perform following operations:
//  Insert a node
//  Delete a node
//  Search a node
//  Preorder Traversal
//  Postorder Traversal
//  Inorder Traversal
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int Info;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node *root, int value){
    if (root == NULL){
        struct Node *new = (struct Node*)malloc(sizeof(struct Node));

        new->Info = value;
        new->left = NULL;
        new->right = NULL;

        return new;
    }

    if (value < root->Info){
        root->left = insert(root->left, value);
    }
    else if (value > root->Info){
        root->right = insert(root->right, value);
    }

    return root;
}
void deleteNode(struct Node *root, int value){
    if (root == NULL){
        return;
    }

    if (value < root->Info){
        deleteNode(root->left, value);
    }
    else if (value > root->Info){
        deleteNode(root->right, value);
    }
    else{
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if (root->left == NULL){
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL){
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else{
            struct Node *temp = findMin(root->right);
            root->Info = temp->Info;
            deleteNode(root->right, temp->Info);
        }
    }
}
void searchNode(struct Node *root, int value){
    if (root == NULL){
        printf("Value not found in the BST.\n");
        return;
    }

    if (value < root->Info){
        searchNode(root->left, value);
    }
    else if (value > root->Info){
        searchNode(root->right, value);
    }
    else{
        printf("Value found in the BST.\n");
    }
}

void preorderTraversal(struct Node *root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->Info);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct Node *root){
    if (root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->Info);
}
void inorderTraversal(struct Node *root){
    if (root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->Info);
    inorderTraversal(root->right);
    
}
int main(){
    struct Node *root = NULL;
    int n, value;

    printf("Enter a number of element: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Enter a value you want to insert: ");
        scanf("%d", &value);
        root = insert(root,value);
    }
    while (1)
    {
       
    }
    

   
    
}