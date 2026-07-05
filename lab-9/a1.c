// Write a program to copy a linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void firstlinkedlist() {
    struct node *n1node, *save;

    n1node = (struct node *)malloc(sizeof(struct node));

    printf("Enter the new info: ");
    scanf("%d", &n1node->info);

    n1node->link = NULL;

    if (first1 == NULL) {
        first1 = n1node;
    } else {
        save = first1;
        while (save->link != NULL) {
            save = save->link;
        }
        save->link = n1node;
    }
}

void copylinkedlist()
{
    struct node *save, *prev = NULL;

    if (first1 == NULL)
    {
        printf("First list is empty.\n");
        return;
    }

    save = first1;

    while (save != NULL)
    {
        struct node *n2node;

        n2node = (struct node *)malloc(sizeof(struct node));
        n2node->info = save->info;
        n2node->link = NULL;

        if (first2 == NULL)
        {
            first2 = n2node;
        }
        else
        {
            prev->link = n2node;
        }

        prev = n2node;
        save = save->link;
    }
}

void display()
{
    struct node *save = first2;

    if (first2 == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("\nCopied Linked List:\n");
        while (save != NULL)
        {
            printf("%d ", save->info);
            save = save->link;
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        firstlinkedlist();
    }

    copylinkedlist();

    display();

    return 0;
}