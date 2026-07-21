// WAP to delete alternate nodes of a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lpter;
    struct node *rpter;
};

struct node *first = NULL;

void insertlast()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter info: ");
    scanf("%d", &newnode->info);

    newnode->rpter = NULL;

    if (first == NULL)
    {
        newnode->lpter = NULL;
        first = newnode;
        return;
    }

    temp = first;

    while (temp->rpter != NULL)
        temp = temp->rpter;

    temp->rpter = newnode;
    newnode->lpter = temp;
}

void display()
{
    struct node *temp;

    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = first;

    while (temp != NULL)
    {
        printf("%d", temp->info);
        temp = temp->rpter;
    }

    printf("NULL\n");
}

void deleteAlternate()
{
    struct node *save, *prev;

    prev = first;

    while (prev != NULL && prev->rpter != NULL)
    {
        save = prev->rpter;

        prev->rpter = save->rpter;

        if (save->rpter != NULL)
            save->rpter->lpter = prev;

        free(save);

        prev = prev->rpter;
    }
}

void main()
{
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        insertlast();
    }

    
    display();

    deleteAlternate();

    display();
}