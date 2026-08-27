// Write  a  program  to  construct  a  binary  tree  from  given  Post in and  Pre in 
// traversal sequence.

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

int findInPostorder(int postorder[], int start, int end, int value) {
	for (int index = start; index <= end; index++) {
		if (postorder[index] == value) {
			return index;
		}
	}

	return -1;
}

struct Node *constructTree(int preorder[], int postorder[], int *preorderIndex,
		int start, int end) {
	struct Node *root;
	int leftRootIndex;

	if (start > end) {
		return NULL;
	}

	root = createNode(preorder[*preorderIndex]);
	(*preorderIndex)++;

	if (start == end) {
		return root;
	}

	leftRootIndex = findInPostorder(postorder, start, end - 1,
			preorder[*preorderIndex]);
	if (leftRootIndex == -1) {
		free(root);
		return NULL;
	}

	root->left = constructTree(preorder, postorder, preorderIndex,
			start, leftRootIndex);
	root->right = constructTree(preorder, postorder, preorderIndex,
			leftRootIndex + 1, end - 1);

	return root;
}

void inorder(struct Node *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void freeTree(struct Node *root) {
	if (root != NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int main(void) {
	struct Node *root;
	int numberOfElements;
	int preorderIndex = 0;

	printf("Enter the number of elements: ");
	scanf("%d", &numberOfElements);

	if (numberOfElements <= 0) {
		printf("The tree must contain at least one element.\n");
		return 0;
	}

	int preorder[numberOfElements];
	int postorder[numberOfElements];

	printf("Enter the preorder traversal: ");
	for (int index = 0; index < numberOfElements; index++) {
		scanf("%d", &preorder[index]);
	}

	printf("Enter the postorder traversal: ");
	for (int index = 0; index < numberOfElements; index++) {
		scanf("%d", &postorder[index]);
	}

	root = constructTree(preorder, postorder, &preorderIndex,
			0, numberOfElements - 1);

	if (root == NULL) {
		printf("Invalid traversal sequences.\n");
		return 0;
	}

	printf("Inorder traversal of the constructed tree: ");
	inorder(root);
	printf("\n");

	freeTree(root);
	return 0;
}