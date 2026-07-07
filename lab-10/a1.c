// Write a program to sort elements of a linked list.
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
void sortlinkedlist()
{
    struct node *save, *perv;
    int temp;
    if (first1 == NULL)
    {
        printf("First list is empty.\n");
        return;
    }
    else
    {    
        save = first1;
        perv = save->link;
        while (save != NULL)
        {
           perv=save->link;
         while (perv!=NULL)
         {
            
            if (save->info > perv->info)
            {
               temp=save->info;
               save->info=perv->info;
               perv->info=temp;
            }
            perv=perv->link;
         }
         save=save->link;
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

   sortlinkedlist();

    displaylinkedlist();

    return 0;
}