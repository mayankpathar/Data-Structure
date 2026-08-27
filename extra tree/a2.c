#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int Info;
    struct Node *left;
    struct Node *right;
}Node;
Node* insert(Node *root, int value){
    if (root == NULL){
        Node *new = (Node*)malloc(sizeof(Node));

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
int findHeight(Node *root){
    int leftHeight;
    int rightHeight;

    if(root == NULL){
        return 0;
    }
    leftHeight = findHeight(root ->left);
    rightHeight = findHeight(root ->right);

    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
}
void checkballance(Node *root){
    int leftHeight;
    int rightHeight;
    int ballance;

    if(root == NULL){
        return;
    }
    checkballance(root ->left);

    leftHeight = findHeight(root ->left);
    rightHeight = findHeight(root ->right);

    ballance = leftHeight - rightHeight;

    if(ballance >= 2){
        printf("critical Node");
    }
    else if(ballance == 0){
        printf("Ballance Node");
    }
    else if(ballance == 1){
        printf("left Heavy");
    }
    else if (ballance == -1)
    {
        printf("right Heavy");
    }
    
    else{
        printf("ballnaced");
    }

    checkballance(root ->right);
}

void inorderTraversal( Node *root){
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

    checkballance(root);
    return 0;
}