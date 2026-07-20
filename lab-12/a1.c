//  54. Write a menu driven program to implement following operations on the doubly linked list.

// 1 Insert a node at the front of the linked list. 

// 2 Delete a node from specified position. 

// 3 Insert a node at the end of the linked list. (Home Work) 

// 4 Display all nodes. (Home Work)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lpter;
    struct node *rpter;
};

struct node *first = NULL;

void insertFront()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter info: ");
    scanf("%d", &newnode->info);

    newnode->lpter = NULL;
    newnode->rpter = first;

    if (first != NULL)
        first->lpter = newnode;

    first = newnode;

    printf("Node Inserted.\n");
}

void insertEnd()
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

void deletePosition()
{
    struct node *temp;
    int pos, i;

    if (first == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    printf("Enter Position: ");
    scanf("%d", &pos);

    temp = first;

    if (pos == 1)
    {
        first = first->rpter;

        if (first != NULL)
            first->lpter = NULL;

        free(temp);
        printf("Node Deleted.\n");
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->rpter;

    if (temp == NULL)
    {
        printf("Invalid Position.\n");
        return;
    }

    if (temp->rpter != NULL)
        temp->rpter->lpter = temp->lpter;

    if (temp->lpter != NULL)
        temp->lpter->rpter = temp->rpter;

    free(temp);

    printf("Node Deleted.\n");
}

void display()
{
    struct node *temp;

    if (first == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    temp = first;

    printf("\nDoubly Linked List:\n");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->info);
        temp = temp->rpter;
    }

    printf("NULL\n");
}
int main()
{
    int n,m;
    printf("Enter the number of insertfirst nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        insertFront();
        
    }
    printf("Enter the number of lastfirst nodes: ");
    scanf("%d", &m);
    for (int i = 0; i <m; i++)
    {
        insertEnd();
    }
    
    display();
    deletespecified();
    display();  
}