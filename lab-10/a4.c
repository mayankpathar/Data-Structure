// Write a program to swap two consecutive nodes in the linked list.->
// Don’t change the values of nodes, implement by changing the link of the nodes.

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
void swaplinkedlist(){
    struct node *prev,*save;
    int temp;
    prev = first1;
    save = prev->link;
    while (save!=NULL)
    {   temp=prev->info;
        prev->info=save->info;
        save->info=temp;
        prev=save->link;
        if (prev!=NULL)
        {
            save=prev->link;
        }
        else{
            break;
        }
        
    }
    
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

    swaplinkedlist();

    displaylinkedlist();

    return 0;
}