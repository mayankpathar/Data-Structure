// WAP to find the smallest and largest elements in the Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *createNode(int data) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	if (newNode == NULL) {
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node *insert(struct Node *root, int data) {
	if (root == NULL) {
		return createNode(data);
	}

	if (data < root->data) {
		root->left = insert(root->left, data);
	} else if (data > root->data) {
		root->right = insert(root->right, data);
	}

	return root;
}

int findSmallest(struct Node *root) {
	while (root->left != NULL) {
		root = root->left;
	}

	return root->data;
}

int findLargest(struct Node *root) {
	while (root->right != NULL) {
		root = root->right;
	}

	return root->data;
}

void freeTree(struct Node *root) {
	if (root != NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int main(void) {
	struct Node *root = NULL;
	int numberOfElements;
	int value;

	printf("Enter the number of elements: ");
	scanf("%d", &numberOfElements);

	if (numberOfElements <= 0) {
		printf("The tree must contain at least one element.\n");
		return 0;
	}

	printf("Enter the elements: ");
	for (int index = 0; index < numberOfElements; index++) {
		scanf("%d", &value);
		root = insert(root, value);
	}

	printf("Smallest element: %d\n", findSmallest(root));
	printf("Largest element: %d\n", findLargest(root));

	freeTree(root);
	return 0;
}
