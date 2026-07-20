// WAP to split a circular linked list into two halves.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Info;
    struct Node *link;
};

struct Node *First = NULL;
struct Node *Last = NULL;

void insert() {
    struct Node *node;

    node = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Info: ");
    scanf("%d", &node->Info);

    if (First == NULL) {
        First = Last = node;
        node->link = First;
    }
    else {
        Last->link = node;
        Last = node;
        Last->link = First;
    }
}

void splitList(struct Node **First1, struct Node **First2) {
    struct Node *half, *full;

    if (First == NULL)
        return;

    half = First;
    full = First;

    while (full->link != First && full->link->link != First) {
        half = half->link;
        full = full->link->link;
    }

    if (full->link->link == First) {
        full = full->link;
    }

    *First1 = First;
    *First2 = NULL;

    if (First->link != First)
        *First2 = half->link;

    half->link = *First1;

    if (*First2 != NULL)
        full->link = *First2;
    else
        full->link = *First1;   
}

void display(struct Node *First) {
    struct Node *temp;

    if (First == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = First;
    do {
        printf("%d -> ", temp->Info);
        temp = temp->link;
    } while (temp != First);
    printf("(Back to First)\n");
}

int main() {
    int n;
    struct Node *First1 = NULL;
    struct Node *First2 = NULL;

    printf("Enter number of Nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        insert();
    }

    printf("Original Circular List:\n");
    display(First);

    splitList(&First1, &First2);

    printf("\nFirst Half:\n");
    display(First1);

    printf("\nSecond Half:\n");
    display(First2);

    return 0;
}