// WAP to swap Kth node from beginning with Kth node from end in a singly linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;

void firstlinkedlist()
{
    struct node *n1node, *save;

    n1node = (struct node *)malloc(sizeof(struct node));

    printf("Enter the new info: ");
    scanf("%d", &n1node->info);

    n1node->link = NULL;

    if (first1 == NULL)
    {
        first1 = n1node;
    }
    else
    {
        save = first1;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = n1node;
    }
}
void swap()
{
    struct node *save = first1, *k1 = first1, *k2 = first1;
    int count = 0, n, temp;

    printf("enter the number: ");
    scanf("%d", &n);

    while (save != NULL)
    {
        count++;
        save = save->link;
    }

    if (first1 == NULL || n <= 0 || n > count)
    {
        printf("Invalid position.\n");
        return;
    }

    for (int i = 1; i < n; i++)
    {
        k1 = k1->link;
    }

    for (int i = 1; i < count - n + 1; i++)
    {
        k2 = k2->link;
    }

    temp = k1->info;
    k1->info = k2->info;
    k2->info = temp;
}
void displaylinkedlist()
{
    struct node *save;

    if (first1 == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    save = first1;

    while (save != NULL)
    {
        printf("%d\t", save->info);
        save = save->link;
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

    swap();

    displaylinkedlist();

    return 0;
}