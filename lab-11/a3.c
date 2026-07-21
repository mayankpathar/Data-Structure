// Write a program to perform addition of two polynomial equations using appropriate data structure.
// Write a program to perform addition of two polynomial equations
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Info;
    int power;
    struct Node *link;
};

struct Node *First1 = NULL, *Last1 = NULL;
struct Node *First2 = NULL, *Last2 = NULL;
struct Node *First3 = NULL, *Last3 = NULL;

void insert(struct Node **First, struct Node **Last) {
    struct Node *node;

    node = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Coefficient: ");
    scanf("%d", &node->Info);

    printf("Enter Power: ");
    scanf("%d", &node->power);

    node->link = NULL;

    if (*First == NULL) {
        *First = *Last = node;
    } else {
        (*Last)->link = node;
        *Last = node;
    }
}

void addPolynomial() {
    struct Node *p = First1;
    struct Node *q = First2;

    while (p != NULL && q != NULL) {
        struct Node *node;
        node = (struct Node *)malloc(sizeof(struct Node));
        node->link = NULL;

        if (p->power == q->power) {
            node->Info = p->Info + q->Info;
            node->power = p->power;
            p = p->link;
            q = q->link;
        }
        else if (p->power > q->power) {
            node->Info = p->Info;
            node->power = p->power;
            p = p->link;
        }
        else {
            node->Info = q->Info;
            node->power = q->power;
            q = q->link;
        }

        if (First3 == NULL) {
            First3 = Last3 = node;
        } else {
            Last3->link = node;
            Last3 = node;
        }
    }

    while (p != NULL) {
        struct Node *node;
        node = (struct Node *)malloc(sizeof(struct Node));

        node->Info = p->Info;
        node->power = p->power;
        node->link = NULL;

        if (First3 == NULL)
            First3 = Last3 = node;
        else {
            Last3->link = node;
            Last3 = node;
        }

        p = p->link;
    }

    while (q != NULL) {
        struct Node *node;
        node = (struct Node *)malloc(sizeof(struct Node));

        node->Info = q->Info;
        node->power = q->power;
        node->link = NULL;

        if (First3 == NULL)
            First3 = Last3 = node;
        else {
            Last3->link = node;
            Last3 = node;
        }

        q = q->link;
    }
}

void display(struct Node *First) {
    struct Node *temp = First;

    while (temp != NULL) {
        printf("%dx^%d", temp->Info, temp->power);

        if (temp->link != NULL)
            printf(" + ");

        temp = temp->link;
    }
    printf("\n");
}

void main() {
    int n, i;

    printf("Enter number of terms in First Polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        insert(&First1, &Last1);

    printf("Enter number of terms in Second Polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        insert(&First2, &Last2);

    addPolynomial();

    printf("\nFirst Polynomial:\n");
    display(First1);

    printf("Second Polynomial:\n");
    display(First2);

    printf("Addition Polynomial:\n");
    display(First3);
}