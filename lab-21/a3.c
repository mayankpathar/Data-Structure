//  Write a program to implement phone book dictionary using Binary Search Tree 
// which provides following operations: 
//  Add new entry in phone book,  
//  Remove entry from phone book,  
//  Search phone number  
//  List all entries in ascending order of name and 
//  List all entries in descending order of name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 20

struct Node {
	char name[NAME_LENGTH];
	char phone[PHONE_LENGTH];
	struct Node *left;
	struct Node *right;
};

struct Node *createNode(const char *name, const char *phone) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	if (newNode == NULL) {
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	strcpy(newNode->name, name);
	strcpy(newNode->phone, phone);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node *addEntry(struct Node *root, const char *name,
		const char *phone) {
	int comparison;

	if (root == NULL) {
		return createNode(name, phone);
	}

	comparison = strcmp(name, root->name);
	if (comparison < 0) {
		root->left = addEntry(root->left, name, phone);
	} else if (comparison > 0) {
		root->right = addEntry(root->right, name, phone);
	} else {
		strcpy(root->phone, phone);
	}

	return root;
}

struct Node *searchEntry(struct Node *root, const char *name) {
	int comparison;

	if (root == NULL) {
		return NULL;
	}

	comparison = strcmp(name, root->name);
	if (comparison == 0) {
		return root;
	}
	if (comparison < 0) {
		return searchEntry(root->left, name);
	}

	return searchEntry(root->right, name);
}

struct Node *findSmallest(struct Node *root) {
	while (root->left != NULL) {
		root = root->left;
	}

	return root;
}

struct Node *removeEntry(struct Node *root, const char *name) {
	int comparison;
	struct Node *successor;

	if (root == NULL) {
		return NULL;
	}

	comparison = strcmp(name, root->name);
	if (comparison < 0) {
		root->left = removeEntry(root->left, name);
	} else if (comparison > 0) {
		root->right = removeEntry(root->right, name);
	} else {
		if (root->left == NULL) {
			successor = root->right;
			free(root);
			return successor;
		}
		if (root->right == NULL) {
			successor = root->left;
			free(root);
			return successor;
		}

		successor = findSmallest(root->right);
		strcpy(root->name, successor->name);
		strcpy(root->phone, successor->phone);
		root->right = removeEntry(root->right, successor->name);
	}

	return root;
}

void listAscending(struct Node *root) {
	if (root != NULL) {
		listAscending(root->left);
		printf("Name: %-20s Phone: %s\n", root->name, root->phone);
		listAscending(root->right);
	}
}

void listDescending(struct Node *root) {
	if (root != NULL) {
		listDescending(root->right);
		printf("Name: %-20s Phone: %s\n", root->name, root->phone);
		listDescending(root->left);
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
	struct Node *root = NULL;
	struct Node *entry;
	char name[NAME_LENGTH];
	char phone[PHONE_LENGTH];
	int choice;

	do {
		printf("\n1. Add new entry\n");
		printf("2. Remove entry\n");
		printf("3. Search phone number\n");
		printf("4. List entries in ascending order\n");
		printf("5. List entries in descending order\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter name: ");
			scanf("%49s", name);
			printf("Enter phone number: ");
			scanf("%19s", phone);
			root = addEntry(root, name, phone);
			printf("Entry added successfully.\n");
			break;
		case 2:
			printf("Enter name to remove: ");
			scanf("%49s", name);
			entry = searchEntry(root, name);
			if (entry == NULL) {
				printf("Entry not found.\n");
			} else {
				root = removeEntry(root, name);
				printf("Entry removed successfully.\n");
			}
			break;
		case 3:
			printf("Enter name to search: ");
			scanf("%49s", name);
			entry = searchEntry(root, name);
			if (entry == NULL) {
				printf("Entry not found.\n");
			} else {
				printf("Phone number: %s\n", entry->phone);
			}
			break;
		case 4:
			listAscending(root);
			break;
		case 5:
			listDescending(root);
			break;
		case 6:
			break;
		default:
			printf("Invalid choice.\n");
		}
	} while (choice != 6);

	freeTree(root);
	return 0;
}