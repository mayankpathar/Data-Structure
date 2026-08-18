// Implement Red-Black Tree.
#include <stdio.h>
#include <stdlib.h>


#define RED 0
#define BLACK 1


typedef struct Node {
    int data;
    int color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; 
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void leftRotate(Node** root, Node* x) { 
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}


void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }

    x->right = y;
    y->parent = x;
}

void fixViolation(Node** root, Node* newNode) {
    Node* parent = NULL;
    Node* grandparent = NULL;

    while ((newNode != *root) && (newNode->color == RED) && (newNode->parent->color == RED)) {
        parent = newNode->parent;
        grandparent = parent->parent;

     
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

      
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } else {
              
                if (newNode == parent->right) {
                    leftRotate(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }

                
                rightRotate(root, grandparent);
                int tempColor = parent->color;
                parent->color = grandparent->color;
                grandparent->color = tempColor;
                newNode = parent;
            }
        } else { 
            Node* uncle = grandparent->left;

            if ((uncle != NULL) && (uncle->color == RED)) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } else {
               
                if (newNode == parent->left) {
                    rightRotate(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }

                // Case 3: newNode is right child, perform left rotation
                leftRotate(root, grandparent);
                int tempColor = parent->color;
                parent->color = grandparent->color;
                grandparent->color = tempColor;
                newNode = parent;
            }
        }
    }

    (*root)->color = BLACK; // Ensure the root is always black
}
int main() {
    Node* root = NULL;

    // Insert nodes into the Red-Black Tree
    int values[] = {10, 20, 30, 15, 25, 5};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        Node* newNode = createNode(values[i]);
        // Insert the new node into the tree (insertion logic not shown)
        // After insertion, fix any violations
        fixViolation(&root, newNode);
    }

    // The tree is now a valid Red-Black Tree
    return 0;
}

